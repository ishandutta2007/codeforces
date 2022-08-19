#include <stdio.h>
#include <iostream>

#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define max(a,b)   (((a) > (b)) ? (a) : (b))

typedef unsigned long long ULL;

ULL compress(vector <int> v)
{
	ULL r = 0;

	for (int i = v.size()-1; i >= 0; --i){
		r *= 2;
		r += v[i];
	}

	return r;
}

const int B = 20;
const int M = (1 << B) + 7;
int ppc[M];

int pop_count(ULL x) 
{
    return ppc[x & ((1 << B) - 1)] + ppc[x >> B];
}

int record = 0;

void BronKerbosch(ULL R, ULL P, ULL X, vector <ULL> &G)
{
	if (P == 0ULL && X == 0ULL)
	{
		record = max(pop_count(R), record);
		return;
	}
	
	for (int i = 0; i < (int)G.size(); i++) {
	    if (X & (1ULL << i)) {
	        if ((P & G[i]) == P)
	            return;
	    }
	}
	
	for (int i = 0; i < G.size(); ++i) 
		if (P & (1ULL << i)){
			BronKerbosch(R | (1ULL << i), P & G[i], X & G[i], G);
			P ^= 1ULL << i;
			X |= 1ULL << i;
		}
}

int max_clique(vector <ULL> &G)
{
	ULL R = 0, P = (1ULL << (int)G.size()) - 1, X = 0;

	BronKerbosch(R, P, X, G);
	return record;
}

int main(void)
{
    for (int i = 1; i < (1 << B); i++)
        ppc[i] = ppc[i >> 1] + (i & 1);
    
	int n, m;
	cin >> n >> m;

	int vertex_number = 1; // giving tickets in order of handles appearing
	map <string, int> v_nums; // for mapping handle to vertex number


	vector <vector <int> > G; // adj matrix
	// zero adj matrix
	G.resize(m);
	for (int i = 0; i < m; ++i)
	  G[i].assign(m, 0);


	vector <int> current_clique;
	// | clique appering in grapth between 1's |
	current_clique.assign(m, 0); // prepare

	for (int i = 0; i < n + 1; ++i)
	{
		int d = 0;

		if (i < n)
		  cin >> d;

		if (d < 2)
		{
			// if both are in accumulated clique -- connect them
			for (int j = 0; j < m; ++j)
				for (int k = 0; k < m; ++k)
					if (j != k && current_clique[j] && current_clique[k])
						G[j][k] = 1, G[k][j] = 1;

			for (int j = 0; j < m; ++j)
				current_clique[j] = 0;
		}
		else
		{
			string handle;
			getline(cin, handle);

			if (v_nums[handle] == 0){
				v_nums[handle] = vertex_number;
				vertex_number++;
			}

			current_clique[v_nums[handle] - 1] = 1; //he is on the clique
		}
	}

	// invert G
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			if (i != j)
				G[i][j] = !G[i][j];
	
	/*for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%i ", G[i][j]);
		printf("\n");
	}*/
	
	vector <ULL> Gc;

	for (int i = 0; i < G.size(); ++i)
		Gc.push_back(compress(G[i]));

	printf("%i", max_clique(Gc));

	//getchar();
	return 0;
}