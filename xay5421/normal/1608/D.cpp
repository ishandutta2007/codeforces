#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int n,fac[N],inv[N],ifac[N];
string s[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	cin>>n;
	int tt[2]={0,0};
	rep(i,1,n){
		cin>>s[i];
		for(auto&x:s[i]){
			if(x!='?'){
				++tt[x=='B'];
			}
		}
	}
	if(tt[0]>n||tt[1]>n){
		puts("0"),exit(0);
	}
	int ans=C(n*2-tt[0]-tt[1],n-tt[0]);
	int flg[2]={1,1};
	rep(i,1,n){
		flg[0]&=s[i][0]!='W'&&s[i][1]!='B';
		flg[1]&=s[i][1]!='W'&&s[i][0]!='B';
	}
	int res=1;
	rep(i,1,n){
		if(s[i]=="??"){
			res=ad(res,res);
		}else{
			if(s[i][0]=='?'){
			}else if(s[i][1]=='?'){
			}else if(s[i][0]==s[i][1]){
				res=0;
			}
		}
	}
	printf("%d\n",su(ad(ans,flg[0],flg[1]),res));
	return 0;
}