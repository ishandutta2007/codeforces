/*
Contest: Codeforces Round #665 (Div.2)
Problem: Codeforces Round #665 (Div.2) B
Author: tzc_wk
Time: 2020.8.21
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
signed main(){
	int T=read();
	while(T--){
		int x1=read(),y1=read(),z1=read();
		int x2=read(),y2=read(),z2=read();
		int ans=min(z1,y2)*2;
		int tmp=min(z1,y2);z1-=tmp;y2-=tmp;
		tmp=min(z1,z2);z1-=tmp;z2-=tmp;
		if(z2>x1+z1) ans-=2*(z2-x1-z1);
		cout<<ans<<endl;
	}
	return 0;
}