#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int ax,ay,bx,by,xs,ys,t,len,x[1000],y[1000];
int go1(int i){
	int xx=xs,yy=ys;
	int dis=0,res=0;
	for(int j=i;j>=0;--j){
		dis+=abs(x[j]-xx)+abs(y[j]-yy);
		if(dis>t)return res;
		++res;
		xx=x[j],yy=y[j];
	}
	for(int j=i+1;j<=len;++j){
		dis+=abs(x[j]-xx)+abs(y[j]-yy);
		if(dis>t)return res;
		++res;
		xx=x[j],yy=y[j];
	}
	return res; 
}
int go2(int i){
	int xx=xs,yy=ys;
	int dis=0,res=0;
	for(int j=i;j<=len;++j){
		dis+=abs(x[j]-xx)+abs(y[j]-yy);
		if(dis>t)return res;
		++res;
		xx=x[j],yy=y[j];
	}
	for(int j=i-1;j>=0;--j){
		dis+=abs(x[j]-xx)+abs(y[j]-yy);
		if(dis>t)return res;
		++res;
		xx=x[j],yy=y[j];
	}
	return res;
}
signed main(){
	rd(x[0]),rd(y[0]),rd(ax),rd(ay),rd(bx),rd(by),rd(xs),rd(ys),rd(t);
	while(x[len]<=(1e18-bx)/ax&&y[len]<=(1e18-by)/ay)++len,x[len]=x[len-1]*ax+bx,y[len]=y[len-1]*ay+by;
	int ans=0;
	for(int i=0;i<=len;++i){
		ans=max(ans,go1(i));
		ans=max(ans,go2(i));
	}
	pt(ans,'\n');
	return 0;
}