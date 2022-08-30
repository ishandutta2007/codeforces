#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back
using namespace std;
const int M = 1<<19;
int drz[2 * M + 5][2];
int pre[M];
int size[M];
vector<int> slo[M];

int d;
void dfs(int v)
{
	d++;
	pre[v] = d;
	size[v] = 1;
	for(int i = 0; i < slo[v].size(); i++) {
		int nei = slo[v][i];
		if (!pre[nei]) {
			dfs(nei);
			size[v] +=  size[nei];
		}
	}
}

void fill(int a, int b, int w) {
	a += M - 1;
	b += M - 1;
	drz[a][0] = w;
	drz[b][0] = w;
	while (a / 2 != b / 2) {
		if (a % 2 == 0) {
			drz[a + 1][0] = w;
		}
		if (b % 2 == 1) {
			drz[b - 1][0] = w;
		}
		a /= 2;
		b /= 2;
	}
}

void empty(int a, int w) {
	a += M - 1;
	while (a) {
		drz[a][1] = w;
		a /= 2;
	}
}

int read_fill(int a) {
	int maxi = 0;
	a += M - 1;
	while (a) {
		maxi = max(maxi, drz[a][0]); 
		a /= 2;
	}
	return maxi;
}

int read_empty(int a, int b) {
	a += M - 1;
	b += M - 1;
	int maxi = 0;
	maxi = max(maxi, drz[a][1]);
	maxi = max(maxi, drz[b][1]);
	while (a / 2 != b / 2) {
		if (a % 2 == 0) {
			maxi = max(maxi, drz[a + 1][1]);
		}
		if (b % 2 == 1) {
			maxi = max(maxi, drz[b - 1][1]);
		}
		a /= 2;
		b /= 2;
	}
	return maxi;
}

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int n, q;
	cin>>n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin>>a>>b;
		slo[a].PB(b);
		slo[b].PB(a);
	}
	dfs(1);
	cin>>q;
	for (int i = 1; i <= q; i++) {
		int c, v;
		cin>>c>>v;
		if (c == 1) {
			fill(pre[v], pre[v] + size[v] - 1, i);
		} else if (c == 2) {
			empty(pre[v], i);
		} else {
			int filling = read_fill(pre[v]);
			int empting = read_empty(pre[v], pre[v] + size[v] - 1);
			if (filling == 0 || filling < empting) {
				cout<<"0\n";
			}
			else {
				cout<<"1\n";
			}
		}
	}
	
	// nie zapomnij o ll
	return 0;
}