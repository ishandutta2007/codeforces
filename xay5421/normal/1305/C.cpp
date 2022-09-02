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
const int N=200005;
int n,m,a[N],b[N];
signed main(){
	rd(n),rd(m);
	for(int i=1;i<=n;++i)rd(a[i]);
	sort(a+1,a+1+n);
	int res=1;
	for(int i=1;i<=n;++i){
		a[i]%=m;
		for(int j=0;j<m;++j)if(b[j]){
			res=1LL*res*(a[i]-j+m)%m;
			if(res==0){
				puts("0");
				return 0;
			}
		}
		++b[a[i]];
	}
	pt(res,'\n');
	return 0;
}