#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=4000005,P=998244353;
int n,m,fac[N],inv[N],iv[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*inv[k2]%P*inv[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=iv[0]=iv[1]=1;
	rep(i,2,N-1)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,iv[i]=inv[i];
	rep(i,2,N-1)inv[i]=1LL*inv[i-1]*inv[i]%P;
	cin>>n>>m;
	int a=(1LL*n*iv[m+1]+1)%P;
//	rep(i,1,n+1)(a+=1LL*i*C(n+m-i,m-1)%P*fac[n]%P*fac[m]%P)%=P;
//	a=1LL*a*inv[n+m]%P;
	int ans=0;
	rep(i,1,n)(ans+=1LL*C(n,i)*((i+1)&1?-1:1)*a%P*(i+m)%P*iv[i]%P)%=P;
	cout<<(ans+P)%P<<endl;
	return 0;
}