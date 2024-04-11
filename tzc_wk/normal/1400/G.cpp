/*
Contest:
Problem:
Author: tzc_wk
Time:
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
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
int n=read(),m=read();
int cf[300005],l[300005],r[300005],cnt[300005],a[25],b[25];
const int MOD=998244353;
int fac[300005],inv[300005];
int qpow(int x,int e){
	int ans=1;while(e){if(e&1) ans=ans*x%MOD;x=x*x%MOD;e>>=1;} return ans;
}
inline void prework(){
	fac[0]=1;for(int i=1;i<=300000;i++) fac[i]=fac[i-1]*i%MOD;
	for(int i=0;i<=300000;i++) inv[i]=qpow(fac[i],MOD-2);
}
int sum[300005][45];
inline int getc(int x,int y){
	if(x<y||x<0||y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
signed main(){
	prework();
	fz(i,1,n){
		l[i]=read(),r[i]=read();
		cf[l[i]]++;cf[r[i]+1]--;
	}
	int num=0;
	fz(i,1,n){num+=cf[i];cnt[i]=num;}
	fz(i,1,m) a[i]=read(),b[i]=read();
	fz(i,0,40){
		fz(j,1,n){
			sum[j][i]=(sum[j-1][i]+getc(cnt[j]-i,j-i))%MOD;
		}
	}
//	cout<<sum[3][1]<<" "<<sum[1][1]<<endl;
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		int _l=1,_r=n;
		set<int> st;
		fz(j,1,m){
			if(i>>(j-1)&1){
				_l=max(_l,l[a[j]]);_r=min(_r,r[a[j]]);st.insert(a[j]);
				_l=max(_l,l[b[j]]);_r=min(_r,r[b[j]]);st.insert(b[j]);
			}
		}
		if(_l>_r) continue;
		int calc=(sum[_r][st.size()]-sum[_l-1][st.size()]+MOD)%MOD;
		int cnt1=__builtin_popcount(i);
		if(cnt1&1) ans=(ans-calc+MOD)%MOD;
		else ans=(ans+calc)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}