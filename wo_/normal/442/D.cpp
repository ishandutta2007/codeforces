#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

const int inf=1e9;

int dp[1100100][25];

vector<int> chs[1100100];

int ps[1100100];
int N;

void getTree(){
	for(int i=1;i<N;i++){
		chs[ps[i]].push_back(i);
	}
}

int ans[1100100];

void upd(int &a,int x){
	if(a==inf){
		a=x;
		return;
	}
	if(x==inf) return;
	a=max(a,x);
}

void solve(){
	for(int i=0;i<N;i++){
		for(int j=0;j<25;j++){
			if(j==1) dp[i][j]=i;
			else dp[i][j]=inf;
		}
	}
	for(int v=N-1;v>=1;v--){
		if(chs[v].size()==0) continue;
		for(int c=1;c<25;c++){
			int min_val=inf;
			int min_id=-1;
			for(int j=0;j<chs[v].size();j++){
				int u=chs[v][j];
				int nval=dp[u][c-1];
				if(nval<min_val){
					min_val=nval;
					min_id=j;
				}
			}
			for(int j=0;j<chs[v].size();j++){
				int u=chs[v][j];
				if(j==min_id){
					dp[v][c]=min(dp[v][c],dp[u][c]);
				}else{
					dp[v][c]=min(dp[v][c],dp[u][c-1]);
				}
			}
		}
	}
	for(int i=0;i<N;i++) ans[i]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<25;j++){
			int t=dp[i][j];
			if(t==inf) continue;
			ans[t]=max(ans[t],j);
		}
	}
	for(int i=1;i<N;i++){
		ans[i]=max(ans[i],ans[i-1]);
	}
}

void input(){
	scanf("%d",&N);
	N++;
	for(int i=1;i<N;i++){
		int v;
		scanf("%d",&v);
		v--;
		ps[i]=v;
	}
}

int main(){
	input();
	getTree();
	solve();
	for(int i=1;i<N;i++){
		printf("%d%c",ans[i],i==N-1?'\n':' ');
	}
	return 0;
}