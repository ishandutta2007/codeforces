#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const LL div2 = 5e8+4;
const int N = 100010;

LL l, r;
LL n1[100],n2[100],s1[100],s2[100];

LL submod(LL x,LL y){
	return (x-y+MOD)%MOD;
}

LL calc(LL x){
	LL d=0,ans=0;
	int n=0;
	while(d<x/2)d=d*2+1,++n;
	rep(i,1,n/2)ans=(ans+s1[i]+s2[i])%MOD;
	if(n%2){
		ans=(ans+s1[n/2+1])%MOD;
		ans=ans+(n2[n/2]+2+n2[n/2]+2*(x-d))%MOD*((x-d)%MOD)%MOD*div2%MOD;
	}else{
		ans=ans+(n1[n/2]+2+n1[n/2]+2*(x-d))%MOD*((x-d)%MOD)%MOD*div2%MOD;
	}
	return ans%MOD;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>l>>r;
	LL d=1;
	n1[0]=-1;n2[0]=s1[0]=s2[0]=0;
	rep(i,1,35){
		n1[i]=(n1[i-1]+d*2)%MOD;
		s1[i]=(n1[i-1]+2+n1[i])%MOD*d%MOD*div2%MOD;
		d=d*2%MOD;
		n2[i]=(n2[i-1]+d*2)%MOD;
		s2[i]=(n2[i-1]+2+n2[i])%MOD*d%MOD*div2%MOD;
		d=d*2%MOD;
		//cout<<n1[i]<<" "<<n2[i]<<" "<<s1[i]<<" "<<s2[i]<<endl;
	}
	//cout<<calc(r)<<" "<<calc(l-1)<<endl;
	cout<<submod(calc(r),calc(l-1))<<endl;
	return 0;
}