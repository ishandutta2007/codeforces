#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
const int M=262144;

int D[2*M][2];
vector<int> V[200003], W;
vector<pair<int, int> > ve;

/*int sum(int p, int k)
{
	p+=M;
	k+=M;
	int w=D[p][d];
	if(p!=k) w+=D[k][d];
	while(p/2!=k/2)
	{
		if(p%2==0) w+=D[p+1][d];
		if(k%2==1) w+=D[k-1][d];
		p/=2;
		k/=2;
	}
	return w;
}*/

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.S<b.S;
}

void add(int a, int w)
{
	a+=M;
	D[a][0]+=w;
	D[a][1]+=w;
	while(a>1)
	{
		a/=2;
		D[a][0]=D[2*a][0]+D[2*a+1][0];
		D[a][1]=min(D[2*a][1], D[2*a+1][1]);
	}
	return;
}

int main()
{
	int n, m, k, w=0, ko=0, pop=0, li=1;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<n+m; i++)
	{
		int a;
		scanf("%d", &a);
		ve.PB(MP(a, i));
	}
	sort(ve.begin(), ve.end());
	for(int i=0; i<ve.size(); i++)
	{
		if(ve[i].F!=pop) {pop=ve[i].F; li++;}
		ve[i].F=li;
	}
	sort(ve.begin(), ve.end(), cmp);
	for(int i=0; i<n; i++) V[i%k].PB(ve[i].F);
	for(int i=n; i<m+n; i++) add(ve[i].F, -1);
	for(int i=0; i<k; i++)
	{
		ko=0;
		for(int j=0; j<V[i].size(); j++)
		{
			add(V[i][j], 1);
			if(D[1][0]==0 && D[1][1]==0) W.PB(j*k+i+1-(m-1)*k);
			if(D[1][0]==0)
			{
				add(V[i][ko], -1);
				ko++;
			}
			if(j==V[i].size()-1)
			{
				while(ko<V[i].size())
				{
					add(V[i][ko], -1);
					ko++;
				}
			}
		}
	}
	sort(W.begin(), W.end());
	printf("%d\n", W.size());
	for(int i=0; i<W.size(); i++) printf("%d ", W[i]);
	printf("\n");
	return 0;
}