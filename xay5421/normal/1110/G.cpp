// author: xay5421
// created: Mon Nov  8 16:28:32 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int T,n;
char s[N];
vector<int>e[N*4];
bool sol(){
	rep(i,1,n)if(SZ(e[i])>=4)return 1;
	int tt3=0;
	rep(i,1,n)if(SZ(e[i])==3){
		int tt=0;
		for(auto x:e[i]){
			if((tt+=SZ(e[x])>1)>=2)return 1;
		}
		++tt3;
	}
	if(tt3==2){
		return n&1?1:0;
	}
	return 0;
}
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n*4)e[i].clear();
		rep(i,2,n){
			int u,v;
			rd(u),rd(v);
			e[u].pb(v),e[v].pb(u);
		}
		scanf("%s",s+1);
		rep(i,1,n)if(s[i]=='W'){
			e[i].pb(n+1),e[n+1].pb(i);
			e[n+1].pb(n+2),e[n+2].pb(n+1);
			e[n+1].pb(n+3),e[n+3].pb(n+1);
			n+=3;
		}
		puts(sol()?"White":"Draw");
	}
	return 0;
}