#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
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
const int N=1000005;
int n,a[N][2],bel[N],c[N];
vector<vector<int> >G[N];
void dfs(int k1,int k2){
	for(auto j:G[k1])if(j[1]!=k2&&c[j[1]]==-1){
		c[j[1]]=j[2];
		dfs(j[0],j[1]);
	}
}
signed main(){
	rd(n);
	if(n&1){
		puts("Second");
		fflush(stdout);
		memset(c,-1,sizeof(c));
		for(int i=1;i<=n*2;++i){
			scanf("%d",&bel[i]);
			if(!a[bel[i]][0])a[bel[i]][0]=i;
			else a[bel[i]][1]=i;
		}
		for(int i=1;i<=n;++i){
			G[a[i][0]%n].PB({a[i][1]%n,i,1});
			G[a[i][1]%n].PB({a[i][0]%n,i,0});
		}
		rep(i,0,n-1)
			dfs(i,-1);
		LL cur=0;
		rep(i,1,n){
			cur+=a[i][c[i]];
		}
		if(cur%(n*2)!=0){
			rep(i,1,n)c[i]^=1;
		}
		rep(i,1,n)printf("%d ",a[i][c[i]]);
		puts("");
		fflush(stdout);
		
	}else{
		puts("First");
		fflush(stdout);
		int ind=0;
		for(int i=1;i<=n/2-1;++i){
			bel[++ind]=i;
			bel[++ind]=i;
		}
		bel[++ind]=n/2;
		bel[++ind]=n/2+1;
		for(int i=n/2+2;i<=n;++i){
			bel[++ind]=i;
			bel[++ind]=i;
		}
		bel[++ind]=n/2;
		bel[++ind]=n/2+1;
		rep(i,1,n*2)printf("%d ",bel[i]);
		fflush(stdout);
	}
	return 0;
}