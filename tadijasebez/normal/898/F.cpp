#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct MOD{
	int mod;
	int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
	int sub(int x,int y){x-=y;return x<0?x+mod:x;}
	int mul(int x,int y){return (ll)x*y%mod;}
	int pow(int x,int k){int ans=1;for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);return ans;}
	int inv(int x){return pow(x,mod-2);}
}mod1,mod2;
const int N=1000050;
int sum1[N],sum2[N],i1[N],i2[N],p1[N],p2[N];
char s[N];
bool Check(int fir,int sec,int thi,int sum[],int po[],int in[],MOD mod){
	int h1=sum[fir];
	int h2=mod.sub(sum[fir+sec],mod.mul(sum[fir],po[sec]));
	int h3=mod.sub(sum[fir+sec+thi],mod.mul(sum[fir+sec],po[thi]));
	return mod.add(h1,h2)==h3;
}
int main(){
	mod1.mod=998244353;
	mod2.mod=1e9+9;
	scanf("%s",s+1);
	int n=strlen(s+1);
	p1[0]=1;for(int i=1;i<=n;i++)p1[i]=mod1.mul(p1[i-1],10);
	p2[0]=1;for(int i=1;i<=n;i++)p2[i]=mod2.mul(p2[i-1],10);
	i1[0]=1;i1[1]=mod1.inv(10);for(int i=2;i<=n;i++)i1[i]=mod1.mul(i1[i-1],i1[1]);
	i2[0]=1;i2[1]=mod2.inv(10);for(int i=2;i<=n;i++)i2[i]=mod2.mul(i2[i-1],i2[1]);
	for(int i=1;i<=n;i++)sum1[i]=mod1.add(s[i]-'0',mod1.mul(sum1[i-1],10));
	for(int i=1;i<=n;i++)sum2[i]=mod2.add(s[i]-'0',mod2.mul(sum2[i-1],10));
	for(int len=1;len<=n;len++){
		for(int a=0;a<2;a++){
			int sec=n-len*2-a;
			if(sec>0 && sec<=len){
				if(Check(len,sec,len+a,sum1,p1,i1,mod1) && Check(len,sec,len+a,sum2,p2,i2,mod2) && (s[1]!='0' || len==1) && (s[len+1]!='0' || sec==1) && (s[len+sec+1]!='0' || len+a==1)){
					for(int i=1;i<=len;i++)printf("%c",s[i]);
					printf("+");
					for(int i=len+1;i<=len+sec;i++)printf("%c",s[i]);
					printf("=");
					for(int i=len+sec+1;i<=n;i++)printf("%c",s[i]);
					printf("\n");
					return 0;
				}
				if(Check(sec,len,len+a,sum1,p1,i1,mod1) && Check(sec,len,len+a,sum2,p2,i2,mod2) && (s[1]!='0' || sec==1) && (s[sec+1]!='0' || len==1) && (s[len+sec+1]!='0' || len+a==1)){
					for(int i=1;i<=sec;i++)printf("%c",s[i]);
					printf("+");
					for(int i=sec+1;i<=len+sec;i++)printf("%c",s[i]);
					printf("=");
					for(int i=len+sec+1;i<=n;i++)printf("%c",s[i]);
					printf("\n");
					return 0;
				}
			}
		}
	}
	return 0;
}