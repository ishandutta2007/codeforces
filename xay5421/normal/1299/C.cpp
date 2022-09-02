#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int n,top,a[N];
struct data{
	int l,r,sum;double x;
	data operator+(const data&b)const{
		data c=(data){l,b.r,sum+b.sum};
		c.x=1.*c.sum/(c.r-c.l+1);
		return c;
	}
}st[N];
void push(data k1){
	while(top>0&&k1.x<=st[top].x){
		k1=st[top]+k1;
		--top;
	}
	st[++top]=k1;
}
signed main(){
	rd(n);
	for(int i=1;i<=n;++i){
		rd(a[i]);
	}
	for(int i=1;i<=n;++i){
		push((data){i,i,a[i],1.*a[i]});
	}
	for(int i=1;i<=top;++i){
		for(int j=st[i].l;j<=st[i].r;++j){
			printf("%.10f\n",st[i].x);
		}
	}
	return 0;
}