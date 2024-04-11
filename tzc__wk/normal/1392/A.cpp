/*
Contest: Codeforces Global Round 10
Problem: Codeforces 1392A
Author: tzc_wk
Time: 2020.8.16
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
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,a[200005];
inline void solve(){
	n=read();fz(i,1,n) a[i]=read();
	bool flg=1;fz(i,2,n) if(a[i]!=a[1]) flg=0;
	if(!flg) puts("1");
	else printf("%d\n",n);
}
int main(){
	int T=read();
	while(T--) solve();
	return 0;
}