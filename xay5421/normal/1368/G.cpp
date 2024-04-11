// author: xay5421
// created: Mon Jan 11 18:37:04 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005;
int n,m,ind,tin[N],tou[N],deg[N];
vector<array<int,3> >mod[N];
vector<int>e[N];
LL ans;
void ae(int k1,int k2){e[k1].push_back(k2),++deg[k2];}
int zip(int x,int y){return x*m+y;}
int tg[N*4],mn[N*4],t[N*4];
void pst(int k1,int k2){
	tg[k1]+=k2,mn[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	t[k1]=0;
	if(mn[k1]==mn[k1*2])t[k1]+=t[k1*2];
	if(mn[k1]==mn[k1*2+1])t[k1]+=t[k1*2+1];
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1]=1;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	vector<string>s(n);
	rep(i,0,n-1)cin>>s[i];
	rep(i,0,n-1){
		rep(j,0,m-1){
			if(j+2<m&&s[i][j+1]=='L'&&s[i][j+2]=='R'){
				ae(zip(i,j),zip(i,j+2));
			}
			if(j-2>=0&&s[i][j-1]=='R'&&s[i][j-2]=='L'){
				ae(zip(i,j),zip(i,j-2));
			}
			if(i+2<n&&s[i+1][j]=='U'&&s[i+2][j]=='D'){
				ae(zip(i,j),zip(i+2,j));
			}
			if(i-2>=0&&s[i-1][j]=='D'&&s[i-2][j]=='U'){
				ae(zip(i,j),zip(i-2,j));
			}
		}
	}
	function<void(int,int)>dfs=[&](int k1,int k2){
		tin[k1]=++ind;
		for(const auto&x:e[k1])if(x!=k2)dfs(x,k1);
		tou[k1]=ind;
	};
	rep(i,0,n*m-1)if(!deg[i])dfs(i,0);
	rep(i,0,n-1)rep(j,0,m-1){
		pair<int,int>rg1,rg2;
		if(s[i][j]=='L'){
			rg1=make_pair(tin[zip(i,j)],tou[zip(i,j)]);
			rg2=make_pair(tin[zip(i,j+1)],tou[zip(i,j+1)]);
			if((i+j)&1)swap(rg1,rg2);
		}else if(s[i][j]=='U'){
			rg1=make_pair(tin[zip(i,j)],tou[zip(i,j)]);
			rg2=make_pair(tin[zip(i+1,j)],tou[zip(i+1,j)]);
			if((i+j)&1)swap(rg1,rg2);
		}else continue;
		D("[%d,%d] [%d,%d]\n",rg1.X,rg1.Y,rg2.X,rg2.Y);
		mod[rg1.X].push_back({rg2.X,rg2.Y,1});
		mod[rg1.Y+1].push_back({rg2.X,rg2.Y,-1});
	}
	bud(1,1,n*m);
	rep(i,0,n*m){
		for(const auto&arr:mod[i]){
			add(1,1,n*m,arr[0],arr[1],arr[2]);
		}
		D("i=%d %d\n",i,n*m-(mn[1]==0?t[1]:0));
		ans+=n*m-(mn[1]==0?t[1]:0);
	}
	printf("%lld\n",ans);
	return 0;
}