#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
const int maxm=1000007;
int n,m,cnt=0;
int dist[maxn][maxn],p[maxm],ans[maxm];

void floyd(){
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			char c;
			cin>>c;
			if (c=='1'){
				dist[i][j]=1;
			}
			else{
				dist[i][j]=1007;
			}
		}
	}
	floyd();
	cin>>m;
	for (int i=1;i<=m;++i){
		cin>>p[i];
	}
	int i=1;
	while(i<m){
		ans[++cnt]=i;
//		cout<<i<<" "<<ans[cnt]<<" "<<i+1<<" "<<dist[p[ans[cnt]]][p[i+1]]<<endl;
		while (i<m&&p[ans[cnt]]!=p[i+1]&&dist[p[ans[cnt]]][p[i+1]]==i+1-ans[cnt]){
			i++;
		}
	}
	ans[++cnt]=i;
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;++i){
		cout<<p[ans[i]]<<" ";
	}
	return 0;
}