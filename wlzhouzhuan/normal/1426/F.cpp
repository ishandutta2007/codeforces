#include<bits/stdc++.h>
#define ls ch[x][0]
#define rs ch[x][1]
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

const ll mod=1e9+7;
ll n,pre1[200010],pre2[200010],suf1[200010],suf2[200010],ans;
char str[200010];

inline ll qpow(ll x,ll k){
	ll res=1;
	while(k>0){if(k&1)res=res*x%mod;x=x*x%mod;k>>=1;}
	return res;
}


int main(){
	n=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;i++) {
		pre1[i]=pre1[i-1]+(str[i]=='a');
		pre2[i]=pre2[i-1]+(str[i]=='?');
	}
	for(int i=n;i>=1;i--) {
		suf1[i]=suf1[i+1]+(str[i]=='c');
		suf2[i]=suf2[i+1]+(str[i]=='?');
	}
	for(int i=1;i<=n;i++){
		if(str[i]=='b'){
			ans+=
				(pre1[i]*qpow(3,pre2[i])%mod+pre2[i]*qpow(3,pre2[i]-1)%mod)%mod
				*((suf1[i]*qpow(3,suf2[i])%mod+suf2[i]*qpow(3,suf2[i]-1)%mod)%mod)%mod;
			ans%=mod;
		}
		if(str[i]=='?'){
			ans+=
				(pre1[i-1]*qpow(3,pre2[i-1])%mod+pre2[i-1]*qpow(3,pre2[i-1]-1)%mod)%mod
				*((suf1[i+1]*qpow(3,suf2[i+1])%mod+suf2[i+1]*qpow(3,suf2[i+1]-1)%mod)%mod)%mod;
			ans%=mod;
		}
	}printf("%lld\n",ans);
	return 0;
}