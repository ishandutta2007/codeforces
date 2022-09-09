#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1005;
ll sum[N][N];
int A[N][N],B[N][N],C[N][N],D[N][N];
ll val[N][N];
int main(){
	int n,m,a,b;
	scanf("%i %i %i %i",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%i",&A[i][j]),
			sum[i][j]=A[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(int i=1;i<=n;i++){
		deque<int> dq;
		for(int j=1;j<=m;j++){
			while(dq.size() && A[i][dq.back()]>A[i][j])dq.pop_back();
			while(dq.size() && dq.front()<=j-b)dq.pop_front();
			dq.push_back(j);
			if(j>=b)B[i][j-b+1]=A[i][dq.front()];
		}
	}
	for(int j=1;j<=m-b+1;j++){
		deque<int> dq;
		for(int i=1;i<=n;i++){
			while(dq.size() && B[dq.back()][j]>B[i][j])dq.pop_back();
			while(dq.size() && dq.front()<=i-a)dq.pop_front();
			dq.push_back(i);
			if(i>=a)C[i-a+1][j]=B[dq.front()][j];
		}
	}
	for(int i=1;i<=n-a+1;i++)
		for(int j=1;j<=m-b+1;j++)
			val[i][j]=sum[i+a-1][j+b-1]-sum[i-1][j+b-1]-sum[i+a-1][j-1]+sum[i-1][j-1]-(ll)C[i][j]*a*b;
	vector<pair<int,int>> ord,ans;
	for(int i=1;i<=n-a+1;i++)
		for(int j=1;j<=m-b+1;j++)
			ord.pb({i,j});
	sort(ord.begin(),ord.end(),[&](pair<int,int> a,pair<int,int> b){return val[a.first][a.second]<val[b.first][b.second] || (val[a.first][a.second]==val[b.first][b.second] && a<b);});
	for(auto p:ord){
		int x,y;tie(x,y)=p;
		if(!D[x][y] && !D[x+a-1][y] && !D[x][y+b-1] && !D[x+a-1][y+b-1]){
			for(int i=0;i<a;i++)
				for(int j=0;j<b;j++)
					D[x+i][y+j]=1;
			ans.pb({x,y});
		}
	}
	printf("%i\n",ans.size());
	for(auto p:ans)printf("%i %i %lld\n",p.first,p.second,val[p.first][p.second]);
	return 0;
}