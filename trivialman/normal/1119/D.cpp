#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 100010;

LL n,q,x,y,cnt=0,s[N],d[N],sum[N],per[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>s[i];
	sort(s+1,s+n+1);
	rep(i,2,n)d[i-1]=s[i]-s[i-1];
	sort(d+1,d+n);d[0]=-1;d[n]=2e18;
	LL j=1;
	per[0]=n;
	for(;j<n;++j){
		LL j1=j;
		while(j<n&&d[j]==d[j+1])++j;
		rep(i,j1,j){
			per[i]=per[j1-1]-(j-j1+1);
			sum[i]=sum[j1-1]+(d[j1]-d[j1-1]-1)*per[j1-1]+per[i];
		}
	}
	cin>>q;
	while(q--){
		cin>>x>>y;
		y -= x;
		LL l = upper_bound(d+1,d+n+1,y)-d-1;//lower_bound>=,upper_bound>
		cout<<sum[l]+(y-d[l])*per[l]<<" ";
	}
	return 0;
}