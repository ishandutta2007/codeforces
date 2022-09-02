#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,a[N],x[N],y[N];
signed main(){
	rd(n);
	int all=(1ll<<60)-1;
	for(int i=1;i<=n;++i){
		rd(a[i]);
		x[i]=x[i-1]|a[i];
	}
	for(int i=n;i>=1;--i){
		y[i]=y[i+1]|a[i];
	}
	int ans=0,id=1;
	for(int i=1;i<=n;++i){
		int w=a[i]&(all^x[i-1])&(all^y[i+1]); 
		if(w>ans)ans=w,id=i;
	}
	pt(a[id],' ');
	for(int i=1;i<=n;++i)if(i!=id)pt(a[i],' ');
	return 0;
}