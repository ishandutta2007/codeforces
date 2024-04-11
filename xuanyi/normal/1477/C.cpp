// author: xay5421
// created: Thu Jan 28 23:07:26 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
typedef long long LL;
const int N=5005;
int n,ans[N],len;
bool pd[N];
struct vec{
	int x,y;
	bool operator<(const vec&k)const{
		return make_pair(x,y)<make_pair(k.x,k.y);
	}
}p[N];
LL dis(LL x,LL y){
	return x*x+y*y;
}
int main(){
	rd(n);
	rep(i,1,n){
		rd(p[i].x),rd(p[i].y);
	}
	int lst=min_element(p+1,p+1+n)-p;
	pd[lst]=1;
	ans[++len]=lst;
	rep(_,1,n-1){
		int cur=-1;
		LL mx=-1e18;
		rep(i,1,n)if(!pd[i]){
			LL tem=dis(p[lst].x-p[i].x,p[lst].y-p[i].y);
			if(mx<tem){
				mx=tem;
				cur=i;
			}
		}
		lst=ans[++len]=cur;
		pd[lst]=1;
	}
	rep(i,1,len)printf("%d ",ans[i]);
	return 0;
}