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
const int N=105;
int T,n,a[N],b[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);
		for(int i=1;i<=n;++i){
			rd(a[i]);
		}
		for(int i=1;i<=n;++i)rd(b[i]);
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		for(int i=1;i<=n;++i)pt(a[i],i==n?'\n':' ');
		for(int i=1;i<=n;++i)pt(b[i],i==n?'\n':' ');
	}
	return 0;
}