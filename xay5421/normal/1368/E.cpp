#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
//#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,d[N],num[N];bool vis[N];VI G[N];
signed main(){
	int T;rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)G[i].clear(),d[i]=0,num[i]=2,vis[i]=0;
		rep(i,1,m){
			int k1,k2;rd(k1),rd(k2);
			G[k1].PB(k2),++d[k2];
		}
		queue<int>q;
		rep(i,1,n)if(!d[i])q.push(i);
		while(SZ(q)){
			int k1=q.front();q.pop();
//			D(">>> %d\n",k1);
			for(auto j:G[k1]){
				if(num[k1]!=0)num[j]=min(num[j],num[k1]-1);
				if(!--d[j])q.push(j);
			}
		}
		VI ans;
		rep(i,1,n)if(num[i]==0)ans.PB(i);
		printf("%d\n",SZ(ans));
		for(auto j:ans)printf("%d ",j);puts("");
	}
	return 0;
}