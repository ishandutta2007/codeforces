#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int D = 106; 

bool f[36][D][D*D]; 
bool g[36][D][D*D]; 
int a[36]; 
//int d[100]; 
int st[1000][1000]; 
bool v[1000]; 

int main() {
	int n; 
	cin>>n; 
	for (int i = 1; i <= n; ++i) 
		scanf( "%d", &a[i] ); 
	sort( a+1, a+n+1 ); 
	memset(f, false, sizeof(f)); 
	f[0][0][0] = true; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < D; ++j) 
			for (int k = max(a[i],j*(j-1)/2); k < D*D; ++k) {
				if (f[i-1][j-1][k-a[i]]) {
					g[i][j][k] = true; 
					f[i][j][k] = true; 
				}
				else if (f[i][j-1][k-a[i]]) {
					g[i][j][k] = false; 
					f[i][j][k] = true; 
				}
			}
	}
	for (int i = n; i < D; ++i) 
		if (f[n][i][i*(i-1)/2]) {
			vector<int> d; 
			int s = i*(i-1)/2; 
			int p = n; 
			int j = i; 
			while (j > 0) {
				d.pb(a[p]); 
				int tp = p; 
				if (g[p][j][s]) p--; 
				j--; 
				s -= a[tp]; 
			}
			//for (auto i : d) cout<<i<<endl; 
			//return 0; 
			//reverse(d.begin(), d.end()); 
			//memset(st, 0, sizeof(st)); 
			//for (int j = 0; j < i; ++j) {
				//int t = d[j]; 
				//for (int k = 0; k < j; ++k) 
					//t -= st[j][k]; 
				//for (int k = j+1; k < i; ++k) 
					//if (t > 0) {
						//t--; 
						//st[j][k] = 1; 
						//st[k][j] = 0;  
					//}
					//else {
						//st[j][k] = 0; 
						//st[k][j] = 1; 
					//}
			//}
			memset(v, false, sizeof(v)); 
			for (int j = 0; j < i; ++j) {
				vector<int> a; 
				for (int k = 0; k < i; ++k) 
					if (!v[k]) a.pb(k); 
				sort(a.begin(), a.end(), [&](int x, int y){return d[x] < d[y];} ); 
				int t = d[a[0]]; 
				for (int k = 1; k < (int)a.size(); k++) 
					if (t > 0) {
						st[a[0]][a[k]] = 1; 
						st[a[k]][a[0]] = 0; 
						t--; 
					}
					else {
						st[a[0]][a[k]] = 0; 
						st[a[k]][a[0]] = 1; 
						d[a[k]]--; 
					}
				v[a[0]] = true; 
			}
			cout<<i<<endl; 
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k < i; ++k) printf( "%d", st[j][k] ); 
				puts( "" ); 
			}
			return 0; 
		}
	puts( "=(" ); 
}