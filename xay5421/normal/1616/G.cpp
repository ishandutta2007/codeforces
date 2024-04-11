#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		n+=2;
		vector<tuple<int,int> >es(m);
		vector<vector<int> >e(n),ie(n);
		vector<int>good(n);
		good[0]=1,good[n-2]=1;
		rep(i,1,n-2){
			if(i>1){
				e[0].push_back(i);
				ie[i].push_back(0);
			}
			if(i<n-2){
				e[i].push_back(n-1);
				ie[n-1].push_back(i);
			}
		}
		rep(i,0,m-1){
			int u,v;
			scanf("%d%d",&u,&v);
			es[i]={u,v};
			if(v==u+1){
				good[u]=1;
			}else{
				e[u].push_back(v);
				ie[v].push_back(u);
			}
		}
		vector<int>goes(n);
		vector<tuple<int,int> >segs;
		for(int i=0,j;i<n;i=j){
			j=i+1;
			while(j<n&&good[j-1])++j;
			segs.emplace_back(i,j);
			rep(k,i,j-1)goes[k]=j;
		}
		if(segs.size()<=1){
			printf("%lld\n",1LL*(n-2)*(n-3)/2);
			continue;
		}
		int p1=get<1>(segs[0]);
		int p2=get<0>(segs.back());
		vector<array<int,2> >dp(n,{0,0});
		dp[p1-1][0]=1,dp[p1-1][1]=2;
		rep(i,p1+1,n-1){
			for(auto&x:ie[i]){
				if(goes[x+1]>=i){
					dp[i-1][0]|=dp[x][1];
					dp[i-1][1]|=dp[x][0];
				}
			}
		}
		per(i,p1-1,0){
			for(auto&x:ie[i+1]){
				dp[x][0]|=dp[i][1];
				dp[x][1]|=dp[i][0];
			}
		}
		array<int,4>cnt1={0},cnt2={0};
		rep(i,0,p1-1){
			++cnt1[dp[i][0]];
		}
		rep(i,p2,n-1){
			++cnt2[dp[i-1][0]];
		}
		long long ans=0;
		rep(i,0,3)rep(j,0,3)if(i&j){
			ans+=1LL*cnt1[i]*cnt2[j];
		}
		if(segs.size()==2)ans-=1;
		printf("%lld\n",ans);
	}
	return 0;
}