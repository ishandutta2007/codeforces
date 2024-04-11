//by xay5421 2449670833@qq.com
#include<set>
#include<map>
//#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=100005,K=10005,INF=0x3f3f3f3f3f3f3f3fll;
int h,n,m,k,a[N],c[N],d[K];
struct cmpQ{
	bool operator()(const int&k1,const int&k2){return c[k1]^c[k2]?c[k1]>c[k2]:k1<k2;}
};
std::set<int,cmpQ>Q;
struct cmpS{
	 bool operator()(const int&k1,const int&k2){return d[k1]^d[k2]?d[k1]<d[k2]:k1<k2;}
};
std::set<int,cmpS>S;
signed main(){
	memset(d,63,sizeof(d));
	rd(h),rd(n),rd(m),rd(k);
	rep(i,1,n)rd(a[i]),rd(c[i]);
	int op,k1,k2;d[1]=0;
	rep(i,1,n)if(d[a[i]%k]<=a[i]){
		Q.insert(i);
	}
	while(m--){
		rd(op);
		if(op==1){
			rd(k1);
			S.clear();
			rep(i,0,k-1)if(d[i]!=INF)S.insert(i);
			while(!S.empty()){
				int u=*S.begin();S.erase(S.begin());
				if(d[u]+k1<d[(u+k1)%k]){
					S.erase((u+k1)%k);
					d[(u+k1)%k]=d[u]+k1;
					S.insert((u+k1)%k);
				}
			}
			Q.clear();
			rep(i,1,n)if(d[a[i]%k]<=a[i]){
				Q.insert(i);
			}
		}else if(op==2){
			rd(k1),rd(k2);
			if(d[a[k1]%k]<=a[k1]){
				Q.erase(k1);
				c[k1]-=k2;
				Q.insert(k1);
			}else c[k1]-=k2;
		}else{
			if((int)Q.size()==0){
				puts("0");
			}else{
				k1=*Q.begin();
				Q.erase(Q.begin());
				pt(c[k1],'\n');
				c[k1]=0;
			}
		}
	}
	return 0;
}