/*
Contest: Educational Codeforces Round 90
Problem: Codeforces 1373D
Author: tzc_wk
Time: 2020.6.25
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
int a[200005],b[200005],c[200005];
signed main(){
	int T=read();
	while(T--){
		int n=read();
		fz(i,1,n)	a[i]=read();
		int cnt1=0,cnt2=0;
		int ans=0;
		for(int i=1;i<=n;i+=2){
			if(i+1!=n+1)	b[++cnt1]=a[i+1]-a[i];
			ans+=a[i];
		}
		for(int i=2;i<=n;i+=2)	if(i+1!=n+1)	c[++cnt2]=a[i]-a[i+1];
		int cur=0,mx1=0,mx2=0;
//		fz(i,1,cnt1)	cout<<b[i]<<" ";
//		puts("");
//		fz(i,1,cnt2)	cout<<c[i]<<" ";
//		puts("");
		for(int i=1;i<=cnt1;i++){
			if(cur+b[i]>0){
				cur+=b[i];
			}
			else	cur=0;
			mx1=max(mx1,cur);
		}
		cur=0;
		for(int i=1;i<=cnt2;i++){
			if(cur+c[i]>0){
				cur+=c[i];
			}
			else	cur=0;
			mx2=max(mx2,cur);
		}
//		cout<<mx1<<" "<<mx2<<endl;
		cout<<ans+max(mx1,mx2)<<endl;
	}
	return 0;
}