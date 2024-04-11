#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll mod=1e9+7;
char s[100009];
int len;
ll fac[100009],ni[100009];
ll qpow(ll x,ll y){
	ll t=1;
	while(y){
		if(y%2==1) t=(t*x)%mod;
		x=(x*x)%mod,y/=2;
	}
	return t;
}
ll C(int x,int y){
	return ((fac[y]*ni[x])%mod*ni[y-x])%mod;
}
ll make(int x){
	ll ans=0;
	for(int i=0;i*2<=x;i++)
		(ans+=C(i,x-i))%=mod;
	return ans;	 
}
int main(){
	scanf("%s",s);
	len=strlen(s);
	fac[0]=1;
	ll ans=1;
	ni[0]=1;
	for(int i=1;i<=len;i++) fac[i]=(fac[i-1]*i)%mod,ni[i]=qpow(fac[i],mod-2);
	int posn=0,posu=0;
	for(int i=0;i<len;i++){
		if(s[i]=='m'||s[i]=='w'){
			printf("0\n");
			return 0;
		}	
		if(s[i]=='n') posn++;
		else{
			if(posn>0) (ans*=make(posn))%=mod,posn=0;
		}
		if(i==len-1&&posn>0) (ans*=make(posn))%=mod,posn=0;
		if(s[i]=='u') posu++;
		else{
			if(posu>0) (ans*=make(posu))%=mod,posu=0;
		}
		if(i==len-1&&posu>0) (ans*=make(posu))%=mod,posu=0;
	}
	printf("%lld\n",ans);
	return 0;
}