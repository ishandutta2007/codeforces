#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005,K=20;
int T,n,sum[N],f[N][K],lg[N];
char s[N];
int max_(int i,int j){return sum[i]<sum[j]?j:i;}
int qmax(int l,int r){
	int x=lg[r-l+1];
	return max_(f[l][x],f[r-(1<<x)+1][x]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	rd(T);
	while(T--){
		rd(n),n<<=1;
		scanf("%s",s+1);
		rep(i,1,n)sum[i]=sum[i-1]+(s[i]=='('?1:-1),f[i][0]=i;
		rep(j,1,K-1)rep(i,1,n-(1<<j)+1)f[i][j]=max_(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		int p=1,mx=0,mx_pos=0;
		vector<pair<int,int> >v;
		while(p<=n){
			if(sum[p]>=0){
				if(sum[p]>mx){
					mx=sum[p];
					mx_pos=p;
				}
				++p;
			}else{
				int suf=sum[qmax(p,n)];
				int l=p,r=n,ret=-1;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sum[qmax(mid,r)]>=suf-mx){
						ret=mid;
						l=mid+1;
					}else{
						r=mid-1;
					}
				}
				assert(ret!=-1);
				v.eb(mx_pos+1,ret);
				mx+=sum[ret]-sum[p];
				mx_pos+=ret-p;
				p=ret+1;
			}
		}
		printf("%d\n",SZ(v));
		each(x,v)printf("%d %d\n",get<0>(x),get<1>(x));
	}
	return 0;
}