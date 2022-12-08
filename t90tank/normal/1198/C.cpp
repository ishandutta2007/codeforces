#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 600006;
const int maxm = 500006; 
int n, m; 
bool v[maxn]; 
vi ans; 

int main() {
	ios::sync_with_stdio(false); 
	int T; 
	cin>>T; 
	while (T--) {
		cin>>n>>m; 
		fill(v, v+3*n+1, false); 
		ans.clear(); 
		for (int i = 1; i <= m; ++i) {
			int x, y; 
			cin>>x>>y; 
			if (!v[x] && !v[y]) {
				v[x] = true; v[y] = true; 
				ans.pb(i); 
			}
		}
		if (ans.size() >= n) {
			cout<<"Matching"<<endl; 
			for (int i = 0; i < n; ++i) cout<<ans[i]<<' '; 
			cout<<endl; 
		}
		else {
			cout<<"IndSet"<<endl;  
			int s = 0; 
			for (int i = 1; i <= 3*n && s < n; ++i) 
				if (!v[i]) {
					s++; 
					cout<<i<<' '; 
				}
			cout<<endl;  
		}
	}		
}