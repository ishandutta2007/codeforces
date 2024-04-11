#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 1e9+7;
const int N = 305;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[N], up[N], down[N];
int n, q, t, b, c;
int f[100005];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>q>>t;
	rep(i,1,n)cin>>a[i];
	rep(j,1,q){
		cin>>b>>c;
		down[b] = c, up[c] = b;
	}
	
	int cnt = 0;
	rep(i,1,n) if(!up[i]){
		int x = i;
		while(down[x]){
			t -= a[x];
			if(t<0){
				cout<<"0\n";
				return 0;
			}
			a[down[x]] += a[x];
			x = down[x];
			++cnt;
		}
		++cnt;
	}
	
	if(cnt<n){
		cout<<"0\n";
		return 0;
	}
	
	f[0] = 1;
	rep(i,1,n) rep(j,1,t) if(j>=a[i]) f[j] = (f[j] + f[j-a[i]]) % P;
	cout<<f[t]<<endl;
	return 0;
}