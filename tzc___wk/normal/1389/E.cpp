/*
Contest: Educational Codeforces Round 92
Problem: Codeforces 1389E
Author: tzc_wk
Time: 2020.7.29
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
signed main(){
	int T=read();
	while(T--){
		int m=read(),d=read(),w=read();
		if(d==1){
			cout<<min(m,d)*(min(m,d)-1)/2<<endl;
			continue;
		}
		int gcd=__gcd(d-1,w);
		int t=w/gcd;
		int mn=min(m,d);
		int k=mn/t;
//		cout<<mn<<endl;
		cout<<mn*k-t*k*(k+1)/2<<endl;
	}
	return 0;
}
/*
x,y<=min(m,w)
(x-1)d+y===(y-1)d+x (mod w)
xd+y===yd+x
(x-y)d===x-y (mod w)
(x-y)(d-1)%w=0
*/