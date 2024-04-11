/*
Contest: Grakn Forces 2020
Problem: Codeforces 1408A
Author: tzc_wk
Time: 2020.9.30
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
int n,a[105][3],b[105];
inline void solve(){
	n=read();
	fz(i,1,n) a[i][0]=read();
	fz(i,1,n) a[i][1]=read();
	fz(i,1,n) a[i][2]=read();
	fill0(b);
	fz(i,1,n-1){
		fz(j,0,2) if(a[i][j]!=b[i-1]) b[i]=a[i][j];
	}
	fz(j,0,2) if(a[n][j]!=b[n-1]&&a[n][j]!=b[1]) b[n]=a[n][j];
	fz(i,1,n) cout<<b[i]<<" ";puts("");
}
int main(){
	int T=read();
	while(T--) solve();
	return 0;
}