// ConsoleApplication2.cpp :  "main" 
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>

using namespace std; 

vector<int> e[300000]; 
#define pb push_back
int order[300000]; 
vector<int> bfs; 
bool v[300000]; 

void Bfs() {
	deque<int> q; 
	memset(v, false, sizeof(v)); 
	q.pb(1); 
	bfs.pb(1);
	v[1] = true; 
	while (!q.empty()) {
		int u = q.front(); 
		q.pop_front(); 
		for (auto i : e[u])
			if (!v[i]) {
				q.pb(i); 
				bfs.pb(i); 
				v[i] = true; 
			}
	}
}

bool cmp(int a, int b) { return order[a] < order[b]; }

int main()
{
	int n;
	scanf("%d", &n); 
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
	}
	memset(order, 0, sizeof(order)); 
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf("%d", &x); 
		if (order[x] != 0) {
			cout <<"No" << endl; 
			return 0; 
		}
		order[x] = i; 
	}
	for (int i = 1; i <= n; ++i)
		sort(e[i].begin(), e[i].end(), cmp);
	bfs.clear(); 
	bfs.pb(0); 
	Bfs();
	for (int i = 1; i <= n; ++i)
		if (order[bfs[i]] != i) {
			cout <<"No" << endl;
			return 0;
		}
	cout << "Yes" << endl; 

}

// : Ctrl + F5  >()
// : F5  >

// : 
//   1. /
//   2. 
//   3. 
//   4. 
//   5. >>
//   6. >> .sln 