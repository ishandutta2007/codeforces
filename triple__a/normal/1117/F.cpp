#include<bits/stdc++.h>
using namespace std;
 
const int max=100007;
int n,p;
string s;
int mat[20][20],dp[2<<17];
bool vis[2<<17],v[2<<17];
vector<int> vec[20];
 
int calc(int l,int r){
	int ans=0;
	for (int i=l+1;i<r;++i){
		ans|=(1<<s[i]-'a');
	}
	return ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	cin>>s;
	memset(vis,0,sizeof(vis));
	for (int i=0;i<p;++i){
		for (int j=0;j<p;++j){
			cin>>mat[i][j];
		}
	}
	for (int i=0;i<n;++i){
		vec[s[i]-'a'].push_back(i);
	}
	for (int i=0;i<p;++i){
		for (int j=0;j<p;++j){
			if (mat[i][j]) continue;
			queue<int> q;
			while (!q.empty()){
				q.pop();
			}
			int l=-1,t=0;
			for (int k=0;k<n;++k){
				if (s[k]-'a'==j&&l!=-1){
					int t=calc(l,k);
					q.push(t);
					l=-1;
				}
				if (s[k]-'a'==i){
					l=k;
				}
			}
			memset(v,0,sizeof(v));
			while (!q.empty()){
				int x=q.front();
				vis[x]=1;
				q.pop();
				for (int k=0;k<p;++k){
					if (k==i||k==j) continue;
					if (!v[x|(1<<k)]){
						v[x|(1<<k)]=1;
						q.push(x|(1<<k));
					}
				}
			}
		}
	}
	dp[0]=n;
	int ans=n;
	for (int i=1;i<(1<<p);++i){
		dp[i]=1e9;
	}
	for (int i=1;i<(1<<p);++i){
		if (vis[i]) continue;
		for (int j=0;j<p;++j){
			if ((i>>j&1)&&!vis[i^(1<<j)]){
				dp[i]=dp[i^(1<<j)]-vec[j].size();
//				cout<<i<<" "<<j<<endl;
				ans=min(ans,dp[i]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}