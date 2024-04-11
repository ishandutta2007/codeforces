#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e6+5,mod=1e9+7,inv2=mod+1>>1;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=mul(a,a))if(b&1)c=mul(c,a);
	return c;
}
int n,f[N],pw[N],inv[N],s[N];
void solve(){
	cin>>n;
	pw[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=add(pw[i-1],pw[i-1]);
		inv[i]=mul(inv[i-1],inv2);	
	}
	s[n+1]=0,f[n]=1,s[n]=mul(f[n],inv[n]);
	for(int i=n-1;i>=1;i--){
		int r=min(n,i+i-1);
		f[i]=mul(add(s[i+1],mod-s[r+1]),pw[i]);
		s[i]=add(s[i+1],mul(f[i],inv[i])); 
	}
	for(int i=1,pro=1;i<=n;i++){
		printf("%d\n",mul(f[i],pro));
		if((i+1>>1)!=(i+2>>1))pro=mul(pro,inv2);
	}
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}