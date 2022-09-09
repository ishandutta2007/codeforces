#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2000050;
pair<int,int> bit[N];
void init(){for(int i=0;i<N;i++)bit[i]={N,0};}
void Set(int i,pair<int,int> d){for(i++;i;i-=i&-i)bit[i]=min(bit[i],d);}
pair<int,int> Get(int i){pair<int,int> ans={N,0};for(i++;i<N;i+=i&-i)ans=min(ans,bit[i]);return ans;}
int dp[N],bal[N],go[N],my[N];
vector<pair<int,int>> sgs[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	init();
	for(int i=1,l,r;i<=m;i++){
		scanf("%i %i",&l,&r);
		r=l+r-1;
		sgs[r].pb({l,i});
		bal[l]++;
		bal[r+1]--;
	}
	dp[0]=0;
	Set(0,{dp[0],0});
	for(int i=1;i<=n;i++){
		bal[i]+=bal[i-1];
		dp[i]=N;
		if(!bal[i])dp[i]=dp[i-1],go[i]=i-1;
		for(pair<int,int> p:sgs[i]){
			int j=p.first;
			pair<int,int> tmp=Get(j-1);
			if(dp[i]>tmp.first+1){
				dp[i]=tmp.first+1;
				my[i]=p.second;
				go[i]=tmp.second;
			}
			//dp[i]=min(dp[i],Get(j-1).first+1);//,printf("(%i %i) ",j,Get(j-1));
		}
		Set(i,{dp[i],i});
		//printf("%i ",dp[i]);
	}
	printf("%i\n",m-dp[n]);
	set<int> all;
	for(int i=1;i<=m;i++)all.insert(i);
	int ptr=n;
	while(ptr){
		if(my[ptr])all.erase(my[ptr]);
		ptr=go[ptr];
	}
	for(int i:all)printf("%i ",i);
	return 0;
}