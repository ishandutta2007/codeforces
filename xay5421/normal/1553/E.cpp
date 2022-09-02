// author: xay5421
// created: Thu Jul 22 23:19:08 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int T,n,m,a[N],b[N],c[N];
bool vis[N],ban[N];
bool chk(int x){
	rep(i,1,n){
		c[(i+x+n-1)%n+1]=b[i];
	}
	rep(i,1,n)vis[i]=0;
	int cnt=0;
	rep(i,1,n)if(!vis[i]){
		++cnt;
		int x=i;
		while(!vis[x]){
			vis[x]=1;
			x=c[x];
		}
	}
	if(cnt>=n-m)return 1;
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)rd(a[i]),b[a[i]]=i;
		vector<int>vec;
		rep(i,1,n){
			vec.push_back((b[i]-i+n)%n);
		}
		rep(i,0,n-1)ban[i]=0;
		sort(vec.begin(),vec.end());
		for(int i=0,j;i<SZ(vec);i=j){
			j=i+1;
			while(j<SZ(vec)&&vec[i]==vec[j])++j;
			if((j-i)>=n/3){
				if(chk(vec[i])){
					ban[vec[i]]=1;
				}
			}
		}
		int tt=0;
		rep(i,0,n-1)if(ban[i])++tt;
		printf("%d ",tt);
		rep(i,0,n-1)if(ban[i])printf("%d ",i);
		puts("");
	}
	return 0;
}