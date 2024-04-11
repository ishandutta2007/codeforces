#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert> 
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int T,n,x,a[100005];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(x);
		int ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=n;++i){
			rd(a[i]);
			if(x%a[i]==0)ans=min(ans,x/a[i]);
			else ans=min(ans,max(2ll,x/a[i]+1));
		}
		pt(ans,'\n');
	}
	return 0;
}