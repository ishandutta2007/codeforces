// author: xay5421
// created: Sat Feb  6 12:23:47 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,x,fa[N],dep[N],dp[505][N],sz[N];
vector<int>e[N],nd[N];
char ch[N];
void dfs1(int k1){
	nd[dep[k1]].push_back(k1),sz[k1]=1;
	for(int x:e[k1])dep[x]=dep[k1]+1,dfs1(x),sz[k1]+=sz[x];
}
int main(){
	scanf("%d%d",&n,&x);
	pair<int,char>a=make_pair(x,'a'),b=make_pair(n-x,'b');
	if(a>b)swap(a,b);
	rep(i,2,n)scanf("%d",&fa[i]),e[fa[i]].push_back(i);
	dep[1]=1;
	dfs1(1);
	int mx=*max_element(dep+1,dep+1+n);
	vector<int>t;
	rep(i,1,mx)t.push_back(i);
	sort(t.begin(),t.end(),[&](int x,int y){return SZ(nd[x])<SZ(nd[y]);});
	vector<pair<int,int> >v;
	rep(i,0,SZ(t)-1){
		if(i==0||SZ(nd[t[i]])!=SZ(nd[t[i-1]]))v.emplace_back(SZ(nd[t[i]]),1);
		else v.back().Y+=1;
	}
	dp[SZ(v)][0]=1;
	per(i,SZ(v)-1,0){
		int x=v[i].X,y=v[i].Y;
		vector<int>lst(x,-1);
		rep(j,0,a.X){
			if(dp[i+1][j])lst[j%x]=j;
			if(lst[j%x]==-1||(j-lst[j%x])/x>y)dp[i][j]=0;
			else dp[i][j]=1;
		}
	}
	if(dp[0][a.X]){
		vector<int>need(n+1,0);
		int j=a.X;
		rep(i,0,SZ(v)-1){
			while(!dp[i+1][j]){
				++need[v[i].X];
				j-=v[i].X;
			}
		}
		assert(j==0);
		rep(i,1,n)ch[i]=b.Y;
		rep(i,0,mx){
			if(need[SZ(nd[i])]){
				--need[SZ(nd[i])];
				rep(j,0,SZ(nd[i])-1){
					ch[nd[i][j]]=a.Y;
				}
			}
		}
		printf("%d\n",mx);
		puts(ch+1);
		return 0;
	}else{
		rep(i,0,mx){
			sort(nd[i].begin(),nd[i].end(),[&](int x,int y){return sz[x]<sz[y];});
			if(a.X<b.X)swap(a,b);
			while(SZ(nd[i])&&a.X>0){
				ch[nd[i].back()]=a.Y;
				nd[i].pop_back();
				--a.X;
			}
			while(SZ(nd[i])&&b.X>0){
				ch[nd[i].back()]=b.Y;
				nd[i].pop_back();
				--b.X;
			}
		}
		printf("%d\n",mx+1);
		puts(ch+1);
		return 0;
	}
	return 0;
}