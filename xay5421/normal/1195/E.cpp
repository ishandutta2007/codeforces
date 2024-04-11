#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=3005;
int n,m,a,b,g,x,y,z,ans,v[N][N];
struct que{
	int q[N],val[N],he,ta,mx;
	void clear(){he=1,ta=0;}
	void push(int x,int y){
		while(he<=ta&&q[he]<=y-mx)++he;
		while(he<=ta&&val[ta]>=x)--ta;
		q[++ta]=y,val[ta]=x;
	}
}t[N],q;
signed main(){
	rd(n),rd(m),rd(a),rd(b),rd(g),rd(x),rd(y),rd(z);
	rep(i,1,n)rep(j,1,m)v[i][j]=g,g=(1ll*g*x+y)%z;
	rep(i,1,n)t[i].clear(),t[i].mx=b;
	rep(j,1,m){
		rep(i,1,n)t[i].push(v[i][j],j);
		if(j>=b){
			q.clear(),q.mx=a;
			rep(i,1,n){
				q.push(t[i].val[t[i].he],i);
				if(i>=a)ans+=q.val[q.he];
			}
		}
	}
	pt(ans,'\n');
	return 0;
}