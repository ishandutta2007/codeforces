#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5,mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=mul(a,a))if(b&1)c=mul(c,a);
	return c;
}
int n;
int a[N];
int fac[N],ifac[N],pw[N];
inline int C(int a,int b){
	if(a<b||b<0)return 0;
	return mul(fac[a],mul(ifac[a-b],ifac[b]));	
}
ll s[N];
void solve(){
	n=in();
	ll sum=0;
	for(int i=1;i<=n;i++)a[i]=in(),sum+=a[i],s[i]=s[i-1]+a[i];
	if(sum==0){
		printf("%d\n",pw[n-1]);
		return;	
	}
	ll rs=a[n];int ans=1;
	for(int l=1,p,r=n;l<=n&&s[l]<=sum>>1;l=p+1){
		int L=1,R=0;
		for(p=l;p<n&&a[p+1]==0;p++,L++);
		for(;rs<s[l];r--)rs+=a[r-1];
		if(rs!=s[l])continue;
		R=1;
		for(;r>1&&a[r-1]==0;r--,R++);
		if(s[l]<<1==sum)ans=mul(ans,pw[L]);
		else{
			int v=0;
			for(int i=0;i<=L&&i<=R;i++)
				v=add(v,mul(C(L,i),C(R,i)));
			ans=mul(ans,v);	
		}
	}
	printf("%d\n",ans);
}
int main(){
	n=100000;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;i--)ifac[i-1]=mul(ifac[i],i); 
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=add(pw[i-1],pw[i-1]);
	int t=in();
	while(t--)solve();
	return 0;
}