// author: xay5421
// created: Thu Dec 24 09:54:43 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2005;
int T,n,m,cnt[N],w[N][N];
bool pd[N];
char s[N];
bitset<N>b[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)b[i].reset(),pd[i]=0;
		rep(i,1,m){
			scanf("%s",s+1);
			cnt[i]=count(s+1,s+1+n,'1');
			if(cnt[i]>1){
				rep(j,1,n)if(s[j]=='1')b[j].set(i);
			}
			else cnt[i]=0;
		}
		vector<pair<int,int> >q,ans;
		rep(i,1,n)rep(j,1,n)if(i!=j){
			w[i][j]=b[i].count()-(b[i]&b[j]).count();
			if(!w[i][j])q.emplace_back(i,j);
		}
		auto del=[&](int i){
			rep(k1,1,n)if(b[k1][i]&&!pd[k1])rep(k2,1,n)if(k1!=k2&&!pd[k2]&&w[k1][k2]&&!--w[k1][k2]){
				D("ha\n");
				q.emplace_back(k1,k2);
			}
		};
		auto chk=[&](){
			while(SZ(q)){
				int k1,k2;
				tie(k1,k2)=q.back();
				q.pop_back();
				if(pd[k1]||pd[k2])continue;
				pd[k1]=1;
				ans.emplace_back(k1,k2);
				for(int i=b[k1]._Find_first();i!=N;i=b[k1]._Find_next(i)){
					if(--cnt[i]==1){
						del(i);
					}
				}
				b[k1].reset();
			}
			return SZ(ans)==n-1;
		};
		if(chk()){
			puts("YES");
			rep(i,0,n-2)printf("%d %d\n",ans[i].X,ans[i].Y);
		}else{
			puts("NO");
		}
	}
	return 0;
}