#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int INF=0X3F3F3F3F;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
int T,_ctz[(1<<15)+5],a[15],sum[(1<<15)+5];
int dp[(1<<15)+5][15],dp_[(1<<15)+5][15],ts[(1<<15)+5][15];
vector<tuple<int,int> >path[(1<<15)+5][15],path_[(1<<15)+5][15];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,1,(1<<15)-1)_ctz[i]=__builtin_ctz(i);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,0,n-1)scanf("%d",&a[i]);
		rep(i,1,(1<<n)-1)sum[i]=sum[i&(i-1)]+a[__builtin_ctz(i)];
		vector<int>id(1<<n);
		iota(id.begin(),id.end(),0);
		sort(id.begin(),id.end(),[&](int x,int y){return sum[x]<sum[y];});
		pair<int,int>ans={~INF,INF};
		rep(i,0,(1<<n)-1)rep(j,0,n-1)dp[i][j]=dp_[i][j]=~INF,ts[i][j]=-1;
		for(int l=0,r;l<SZ(id);l=r){
			r=l+1;
			while(r<SZ(id)&&sum[id[l]]==sum[id[r]])++r;
			auto deal=[&](int i,int j){
				if(ts[i][j]!=l){
					ts[i][j]=l;
					dp_[i][j]=dp[i][j];
					path_[i][j]=path[i][j];
				}
			};
			int tmp;
			rep(_,l,r-1){
				int mask=id[_];
				per(i,n-1,0)if((mask>>i)>0){
					int nex=_ctz[mask>>i]+i;
					int imask=(1<<n)-1-mask;
					for(int mm=imask;;--mm&=imask){
						if(dp[mm|mask][nex]<(tmp=(ts[mm][i]!=l?dp[mm][i]:dp_[mm][i])+1)){
							deal(mm|mask,nex);
							dp[mm|mask][nex]=tmp;
							path[mm|mask][nex]=ts[mm][i]!=l?path[mm][i]:path_[mm][i];
							path[mm|mask][nex].eb(mask,nex);
						}
						if(!mm)break;
					}
				}
				dp[mask][_ctz[mask]]=1;
			}
		}
		rep(i,0,n-1)umax(ans,make_pair(dp[(1<<n)-1][i],i));
		printf("%d\n",n-ans.first);
		vector<pair<int,int> >ops;
		auto output=[&](const auto&u,const auto&v){
			rep(i,0,n-1)if((get<0>(u)>>i&1)&&(~get<0>(v)>>i&1)&&i!=get<1>(u)){
				ops.eb(i,get<1>(u));
			}
		};
		auto&ans_path=path[(1<<n)-1][ans.second];
		per(i,SZ(ans_path)-1,0){
			auto pre=i==0?make_tuple(0,0):ans_path[i-1];
			output(ans_path[i],pre);
		}
		static bool vis[20];
		memset(vis,0,sizeof(vis));
		auto rank=[&](int x){
			int res=0;
			rep(j,0,x-1)if(!vis[j])++res;
			return res+1;
		};
		for(auto&x:ops){
			printf("%d %d\n",rank(x.first),rank(x.second));
			vis[x.first]=1;
		}
	}
	return 0;
}