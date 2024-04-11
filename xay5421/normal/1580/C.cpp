// author: xay5421
// created: Thu Sep 30 18:38:39 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,B=350;
int n,m,x[N],y[N],tim[N],t[B][N],cf[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n)rd(x[i]),rd(y[i]),swap(x[i],y[i]);
	rep(_,1,m){
		cf[_]+=cf[_-1];
		int opt,k;
		rd(opt),rd(k);
		if(opt==1){
			tim[k]=_+y[k];
			if(x[k]+y[k]<B){
				int b=x[k]+y[k];
				int j=tim[k]%b;
				rep(i,0,x[k]-1){
					++t[x[k]+y[k]][j++];
					if(j>=b)j=0;
				}
			}else{
				for(int i=tim[k];i<=m+1;i+=x[k]+y[k]){
					int j=min(m+1,i+x[k]-1);
					++cf[i],--cf[j+1];
				}
			}
		}else{
			if(x[k]+y[k]<B){
				int b=x[k]+y[k];
				int j=tim[k]%b;
				rep(i,0,x[k]-1){
					--t[x[k]+y[k]][j++];
					if(j>=b)j=0;
				}
			}else{
				for(int i=tim[k];i<=m+1;i+=x[k]+y[k]){
					int j=min(m+1,i+x[k]-1);
					if(i<_&&j+1>=_)--cf[_];
					--cf[i],++cf[j+1];
				}
			}
		}
		int ans=cf[_];
		rep(i,1,B-1){
			ans+=t[i][_%i];
		}
		printf("%d\n",ans);
	}
	return 0;
}