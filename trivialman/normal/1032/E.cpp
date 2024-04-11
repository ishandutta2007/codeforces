#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 1e9+7;
const int N = 105, M = 10005;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[N], num[N], f[N][M], g[N][M];
int n, m, nm;
bool flag = false;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n) cin>>a[i], num[a[i]]++;
	
	sort(a+1,a+n+1);
	rep(i,1,n) m+=(a[i]!=a[i-1]);
	if(m==1){ cout<<n<<endl; return 0;}
	if(m==2) flag = true;
	
	f[0][0] = 1;
	m = nm = 0;
	rep(w,1,100) if(num[w]){
		swap(f, g);
		rep(j,0,nm) rep(k,0,m) f[j][k] = 0;
		m += w*num[w], nm += num[w];
		
		rrep(i,num[w],0){
			rrep(j,nm,i) rrep(k,m,w*i){
				f[j][k] = min(10, f[j][k] + g[j-i][k-w*i]);
			}
		}
	}
	
	/*rep(i,1,n){
		rep(j,1,m) cout<<f[i][j]<<" ";
		cout<<endl;
	}*/
	
	int ans = 1;
	rep(w,1,100) rep(i,1,num[w]) if(f[i][w*i]==1) ans = max(ans, i);
	
	if(flag){
		int c = 0;
		rep(i,1,n) if(a[i]==a[1]) c++;
		if(f[c][c*a[1]]==1 && f[n-c][(n-c)*a[n]]==1) ans = n;
	}
	cout<<ans<<endl;
	return 0;
}