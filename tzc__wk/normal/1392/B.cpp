/*
Contest: Codeforces Global Round 10
Problem: Codeforces 1392B
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
#define int long long
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
int n,k,a[200005];
inline void solve(){
	n=read();k=read();fz(i,1,n) a[i]=read();
	if(k&1ll){
		int mx=-0x3f3f3f3f;fz(i,1,n) mx=max(mx,a[i]);
		fz(i,1,n) a[i]=mx-a[i];
	}
	else{
		int mn=0x3f3f3f3f;fz(i,1,n) mn=min(mn,a[i]);
		fz(i,1,n) a[i]=a[i]-mn;
	}
	fz(i,1,n) printf("%d ",a[i]);puts("");
}
signed main(){
	int T=read();while(T--) solve();
	return 0;
}