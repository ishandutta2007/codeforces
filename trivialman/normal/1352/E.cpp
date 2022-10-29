#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 8005;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, a[N], s[N];
bitset<N> st;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	a[0] = s[0] = 0;
	while(T--){
		st.reset();
		
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",a+i);
		rep(i,1,n)s[i]=a[i]+s[i-1];
		rep(i,0,n)rep(j,i+2,n) if(s[j]-s[i]<=n) st[s[j]-s[i]]=1;
		
		int ans = 0;
		rep(i,1,n) if(st[a[i]]) ans++;
		cout<<ans<<endl;
	}
	
	return 0;
}