/*
Contest: Codeforces Round #659 (Div.1)
Problem: Codeforces 1383A
Author: tzc_wk
Time: 2020.7.24
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
int n,a[100005],b[100005];
signed main(){
	int T=read();
	while(T--){
		int n=read(),_xor=0;
		fz(i,1,n)	a[i]=read(),_xor^=a[i];
		if(_xor==0){
			puts("DRAW");continue;
		}
		int k=log2(_xor),sum=0;
		fz(i,1,n)	b[i]=a[i]>>k&1,sum+=b[i];
		if(((sum+1)/2)%2==0&&(n-sum)%2==0)	puts("LOSE");
		else								puts("WIN");
	}
	return 0;
}