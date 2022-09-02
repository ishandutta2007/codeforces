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
const int N=5005;
int n,m,a[N],now=0;
signed main(){
	rd(n),rd(m);
	for(int i=1;i<=n;++i)a[i]=i,now+=max(0LL,n-i-i);
	if(m>now){
		puts("-1");return 0;
	}
	int INF=1e9;
	for(int i=n;i>=1;--i){
		int x=(i-1)/2;
		if(now-x>=m)now-=x,a[i]=INF,INF-=5005;
		else{
			a[i]+=(now-m)*2;
			break;
		}
	}
	for(int i=1;i<=n;++i)pt(a[i],i==n?'\n':' ');
	return 0;
}