/*
Contest: Codeforces Round #643
Problem: Codeforces 1355C
Author: tzc_wk
Time: 2020.5.16
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
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
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
//int T=read();
signed main(){
//	while(T--){
		int a=read(),b=read(),c=read(),d=read();
		int sum=(b-a+1)*(c-b+1)*(d-c+1);
		fz(i,a,b){
			int l=c-i,r=d-i;//(i,t<=l,c)&(i,t<=r,d) cannot form
			if(r<b)	continue;
			if(l>c){
				sum-=(b-a+1)*(c-b+1);
				continue;
			}
			if(l<b)	l=b;
//			cout<<l<<" "<<r<<endl;
			if(r>c){
				sum-=(c-l+1)*(c-b+1)-(c-l)*(c-l+1)/2;
				sum-=(r-c)*(c-b+1);
//				cout<<(l-b+1)*(l-b+2)/2<<endl<<(r-c)*(c-b+1)<<endl;
			}
			else{
				sum-=(r-b+1+l-b+1)*(r-l+1)/2;
//				cout<<(r-b+1+l-b+1)*(r-l+1)/2<<endl;
			}
		}
		cout<<sum<<endl;
//	}
	return 0;
}
/*
1 3 5 7
10
1 3 6 9
19
1 33 66 100
6545
1 1 200 300
1 2 2 2
1 1 3 3
*/