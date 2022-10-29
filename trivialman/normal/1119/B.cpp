#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 3010;

LL n,h,a[N],b[N],ans;

bool check(int k){
	rep(i,1,k)b[i]=a[i];
	sort(b+1,b+k+1);
	LL sum=0;
	for(int i=k;i>0;i-=2)sum+=b[i];
	if(sum>h)return false;else return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>h;
	rep(i,1,n)cin>>a[i];
	ans = n;
	rep(i,1,n)if(!check(i)){
		ans=i-1;break;
	}
	cout<<ans<<endl;
	return 0;
}