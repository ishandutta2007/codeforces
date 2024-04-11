#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
const int N = 100005;
 
vector <int> a[N];
int c[N], o, x, y, i, j, n, m;
 
void go(int v, int pr, int k){
	if (k > m){
		return;
	}
	int ok = 1;
	for (int i = 0; i < a[v].size(); i++){
		if (a[v][i] != pr){
			ok = 0;
			go(a[v][i], v, k * c[a[v][i]] + c[a[v][i]]);
		}
	}
	o += ok;
}
 
signed main(){
	cin >> n >> m;
	for (i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	for (i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	go(0, -1, c[0]);
	cout << o << "\n";
}