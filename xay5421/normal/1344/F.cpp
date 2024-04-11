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
const int N=2005;
int n,K,ans[N];
struct mat{
	int x[2][2];
	void reset(){x[0][0]=x[1][1]=1,x[0][1]=x[1][0]=0;}
	mat operator*(const mat&b)const{
		mat c;
		memset(c.x,0,sizeof(c.x));
		rep(i,0,1)rep(j,0,1)rep(k,0,1)c.x[i][j]^=x[i][k]&b.x[k][j];
		return c;
	}
}mm[N];
struct gauss{
	int n;
	bitset<N>f[N];
	int xid[N];
	void sol(int m){
		/*rep(i,1,n){
			rep(j,1,m+1)D("%d ",int(f[i][j]));
			D("\n");
		}*/
		int lst=0;
		rep(i,1,m){
			int pos=-1;
			rep(j,lst+1,n)if(f[j][i]){
				pos=j;
				break;
			}
			if(pos==-1){
				continue;
			}
			++lst,xid[lst]=i;
			swap(f[pos],f[lst]);
			rep(j,lst+1,n)if(f[j][i]){
				f[j]^=f[lst];
			}
		}
		rep(i,lst+1,n){
			if(f[i][m+1])puts("NO"),exit(0);
		}
		/*D("ha\n");
		rep(i,1,n){
			rep(j,1,m+1)D("%d ",int(f[i][j]));
			D("\n");
		}*/
		per(i,lst,1){
			rep(j,xid[i]+1,m){
				if(f[i][j])f[i][j]=0,f[i][m+1]=f[i][m+1]^ans[j];
			}
			ans[xid[i]]=f[i][m+1];
		}
	}
}ga;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	rep(i,1,n)mm[i].reset();
	rep(i,1,K){
		string s;
		cin>>s;
		if(s=="mix"){
			int len;
			scanf("%d",&len);
			rep(i,1,len){
				int k1;
				scanf("%d",&k1);
				ga.f[ga.n+1][k1*2-1]=mm[k1].x[0][0];
				ga.f[ga.n+1][k1*2]=mm[k1].x[0][1];
				ga.f[ga.n+2][k1*2-1]=mm[k1].x[1][0];
				ga.f[ga.n+2][k1*2]=mm[k1].x[1][1];
			}
			cin>>s;
			ga.f[ga.n+1][n*2+1]=s=="B"||s=="Y";
			ga.f[ga.n+2][n*2+1]=s=="R"||s=="Y";
			ga.n+=2;
		}
		else{
			mat cur;
			if(s=="YB"){
				cur=(mat){{{1,0},{1,1}}};
			}
			else if(s=="RB"){
				cur=(mat){{{0,1},{1,0}}};
			}
			else{
				cur=(mat){{{1,1},{0,1}}};
			}
			int len;
			scanf("%d",&len);
			rep(i,1,len){
				int k1;
				scanf("%d",&k1);
				mm[k1]=cur*mm[k1];
			}
		}
	}
	ga.sol(n*2);
	puts("YES");
	rep(i,1,n){
		if(ans[i*2-1]==0&&ans[i*2]==0)putchar('.');
		if(ans[i*2-1]==1&&ans[i*2]==0)putchar('B');
		if(ans[i*2-1]==0&&ans[i*2]==1)putchar('R');
		if(ans[i*2-1]==1&&ans[i*2]==1)putchar('Y');
	}
	puts("");
	return 0;
}