// author: xay5421
// created: Sun Aug  1 22:37:47 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,cnt[N];
int main(){
	rd(n),rd(m);
	int res=n;
	rep(i,1,m){
		int u,v;
		rd(u),rd(v);
		if(u<v)swap(u,v);
		if(!cnt[v]++)--res;
	}
	int Q;
	rd(Q);
	while(Q--){
		int t;
		rd(t);
		if(t==3)pt(res,'\n');
		else if(t==1){
			int u,v;
			rd(u),rd(v);
			if(u<v)swap(u,v);
			if(!cnt[v]++)--res;
		}else{
			int u,v;
			rd(u),rd(v);
			if(u<v)swap(u,v);
			if(!--cnt[v])++res;
		}
	}
	return 0;
}