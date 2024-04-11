#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,a[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		map<int,int>mp;
		rep(i,1,n)rd(a[i]),mp[abs(a[i])]+=1;
		int ans=0;
		for(auto&x:mp){
			if(x.first==0)ans+=min(1,x.second);
			else ans+=min(2,x.second);
		}
		printf("%d\n",ans);
	}
	return 0;
}