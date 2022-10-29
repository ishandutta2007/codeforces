#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define MP make_pair
typedef long long LL;
const LL MOD = 998244353;
const double INF = 1e18;
const int N = 100010;

set<LL> already;
LL ans,res=0,n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL GCD(LL x,LL y){return x==0?y:GCD(y%x,x);}
LL myrand(LL n){return rng()%n+1;}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>n;
	LL l=0,r=1e9,cnt=0;
	while(l<r){
		LL mid = (l + r) / 2;
		cout<<"> "<<mid<<endl;
		cout.flush();
		cin>>ans;
		if(ans)l=mid+1;else r=mid;
		++cnt;
	}
	if(l==0){
		cout<<"! 0 0"<<endl;
		return 0;
	}
	if(n+cnt<=60){
		rep(i,1,n){
			cout<<"? "<<i<<endl;
			cout.flush();
			cin>>ans;
			res = GCD(res, l - ans);
		} 
	}else{
		srand((int)time(0));
		rep(i,1,60-cnt){
			LL x = myrand(n);
			while(already.count(x))x = myrand(n);
			already.insert(x);
			cout<<"? "<<x<<endl;
			cout.flush();
			cin>>ans;
			res = GCD(res, l - ans);
		}
	}
	cout<<"! "<<l-res*(n-1)<<" "<<res<<endl;
	return 0;
}