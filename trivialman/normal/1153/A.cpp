#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 510;

LL n,t,x,y,mi=1e9,ans=0;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>t;
	rep(i,1,n){
		cin>>x>>y;
		if(x<t) x+=((t-x-1)/y+1)*y;
		if(x<mi)mi=x,ans=i;
	} 
	cout<<ans<<endl;
	return 0;
}