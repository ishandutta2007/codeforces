#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 400006; 

vector<int> a[maxn]; 
vector<pair<int,int>> b[maxn]; 
int n, w, h; 
int ans[maxn]; 

int main() {
	scanf( "%d%d%d", &n, &w, &h ); 
	for (int i = 1; i <= n; ++i) {
		int g, p, t; 
		scanf( "%d%d%d", &g, &p, &t ); 
		if (g == 1) {
			a[p-t+100001].pb(w-p); 
			b[p-t+100001].pb(make_pair(-p,i)); 
		}
		else {
			a[p-t+100001].pb(-(h-p)); 
			b[p-t+100001].pb(make_pair(p,i)); 
		}
	}
	for (int i = 0; i < maxn; ++i) {
		sort(a[i].begin(), a[i].end()); 
		sort(b[i].begin(), b[i].end()); 
		//reverse(a[i].begin(),a[i].end()); 
		for (int j = 0; j < (int)a[i].size(); ++j) {
			ans[b[i][j].sec] = a[i][j]; 
		}
		//if (!b[i].empty()) {
			//for (auto x : b[i]) {
				//cout<<'('<<x.fir<<','<<x.sec<<") "; 
			//}
			//puts( "" ); 
		//}
	}
	for (int i = 1; i <= n; ++i)
		if (ans[i] < 0) 
			printf("%d %d\n", w, h-(-ans[i]));
		else printf( "%d %d\n", w-ans[i], h); 
}