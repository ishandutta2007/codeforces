#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int INF=0X3F3F3F3F;
int main(){
	int a,b,c,d;
	scanf("%d%d%*d%*d%d%d%*d%*d",&a,&b,&c,&d);
	if(c<a)swap(a,c);
	if(d<b)swap(b,d);
	int mn[2]={INF,INF};
	int mx[2]={~INF,~INF};
	rep(i,0,3){
		int x,y;
		scanf("%d%d",&x,&y);
		umin(mn[0],x-y);
		umin(mn[1],x+y);
		umax(mx[0],x-y);
		umax(mx[1],x+y);
	}
	rep(i,a,c)rep(j,b,d){
		D("%d %d\n",i-j,i+j);
		if(i-j>=mn[0]&&i-j<=mx[0]&&i+j>=mn[1]&&i+j<=mx[1]){
			puts("YES"),exit(0);
		}
	}
	puts("NO");
	return 0;
}