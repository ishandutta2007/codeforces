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
signed main(){
	int T=read();
	while(T--){
		int x1=read(),y1=read(),x2=read(),y2=read(),x3=read(),y3=read();
		int ans=0;
		fz(i,0,x2){
			if(x3*i>x1) continue;
			int lft=x1-x3*i;
			int w1=lft/y3;
			if(w1>y2) w1=y2;
			int lfts=x2-i,lftw=y2-w1;
			if(x3<y3){
				int cans=y1/x3;
				if(cans>lfts) cans=lfts;
				int lftw2=y1-cans*x3;
				int canw=lftw2/y3;
				if(canw>lftw) canw=lftw;
				ans=max(ans,cans+canw+w1+i);
			}
			else{
				int canw=y1/y3;
				if(canw>lftw) canw=lftw;
				int lfts2=y1-canw*y3;
				int cans=lfts2/x3;
				if(cans>lfts) cans=lfts;
				ans=max(ans,cans+canw+w1+i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}