/*
Contest: -
Problem: SGU 200
Author: tzc_wk
Time: 2020.7.27
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
const int MOD=1e9+7;
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read();
int bs[105][105];
bool vis[505];
int p[505],pcnt=0,pr[505],a[505],tmp[105];
inline void sieve(){
	fz(i,2,500){
		if(!vis[i]){
			p[++pcnt]=i;pr[i]=pcnt;
			for(int j=i;j<=500;j+=i) vis[j]=1;
		}
	}
}
signed main(){
	int cnt=0;
	sieve();
	fill1(bs);
	fz(i,1,n){
		fill0(tmp);
		int x=read();
		for(int j=2;j*j<=x;j++){
			int sum=0;
			if(x%j==0){
				while(x%j==0) x/=j,sum^=1;
				tmp[pr[j]]=sum;
			}
		}
		if(x>1) tmp[pr[x]]=1;
//		fz(j,1,5) cout<<tmp[j]<<" ";puts("");
		bool flg=1,hav=0;
		for(int j=20;j;j--){
			if(!tmp[j]) continue;
			hav=1;
			if(!~bs[j][1]){
				for(int k=1;k<=20;k++) bs[j][k]=tmp[k];
//				cout<<j<<endl;
				flg=0;break;
			}
			else{
				for(int k=1;k<=20;k++) tmp[k]^=bs[j][k];
			}
		}
		if(flg||!hav)	cnt++;
	}
//	cout<<cnt<<endl;
	cout<<(qpow(2,cnt,MOD)-1+MOD)%MOD<<endl;
	return 0;
}