#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n;
struct po{
	int x,y;
	po operator-(const po&b)const{return(po){x-b.x,y-b.y};}
	void init(){
		if(x<0)x=-x,y=-y;
		else if(x==0)y=abs(y);
	}
}a[N],p[N];
int cross(po k1,po k2){return k1.x*k2.y-k1.y*k2.x;}
signed main(){
	rd(n);
	for(int i=1;i<=n;++i){
		rd(a[i].x),rd(a[i].y);
	}
	a[n+1]=a[1];
	for(int i=1;i<=n;++i){
		p[i]=a[i]-a[i+1];
		p[i].init();
	}
	if(n&1){puts("NO");return 0;}
	for(int i=1;i<=n/2;++i){
		if(p[i].x!=p[i+n/2].x||p[i].y!=p[i+n/2].y){
//		if(cross(p[i],p[i+n/2])!=0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}