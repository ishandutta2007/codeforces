/*
Contest: -
Problem: CF1320D
Author: tzc_wk
Time: 2020.6.6
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
const int B=571;
const int MOD=998244353;
int n=read(),m,pre[500005];
int hs0[500005],hs1[500005],P[500005];
char s[500005];
signed main(){
	cin>>s+1;
	P[0]=1;
	fz(i,1,n)	P[i]=P[i-1]*B%MOD;
	m=read();
	fz(i,1,n)	pre[i]=pre[i-1]+(s[i]=='0');
	fz(i,1,n){
		if(s[i]=='0'){
			hs1[i]=(hs1[i-1]*B+(i&1))%MOD;
			hs0[i]=(hs0[i-1]*B+(i&1^1))%MOD;
		}
		else{
			hs1[i]=hs1[i-1];
			hs0[i]=hs0[i-1];
		}
	}
	while(m--){
		int l=read(),r=read(),len=read();
		if(pre[l+len-1]-pre[l-1]!=pre[r+len-1]-pre[r-1]){
			puts("No");continue;
		}
		if((l&1)==(r&1)){
			int hs_1=(hs1[l+len-1]-hs1[l-1]*P[pre[l+len-1]-pre[l-1]]%MOD+MOD)%MOD;
			int hs_2=(hs1[r+len-1]-hs1[r-1]*P[pre[r+len-1]-pre[r-1]]%MOD+MOD)%MOD;
//			cout<<hs_1<<" "<<hs_2<<endl;
			puts((hs_1==hs_2)?"Yes":"No");
		}
		else{
			int hs_1=(hs1[l+len-1]-hs1[l-1]*P[pre[l+len-1]-pre[l-1]]%MOD+MOD)%MOD;
			int hs_2=(hs0[r+len-1]-hs0[r-1]*P[pre[r+len-1]-pre[r-1]]%MOD+MOD)%MOD;
//			cout<<hs_1<<" "<<hs_2<<endl;
			puts((hs_1==hs_2)?"Yes":"No");
		}
	}
	return 0;
}