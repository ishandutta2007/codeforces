#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int d[] = {1,0,-1,0,1};
char ac[] = {'U','R','D','L'};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<vector<int>> x(n,vector<int>(n)),y(n,vector<int>(n));
	rep(i,n){
		rep(j,n)cin>>x[i][j]>>y[i][j];
	}
	rep(i,n)rep(j,n)--x[i][j],--y[i][j];
	queue<pair<int,int>> q;
	char ans[n][n];
	rep(i,n)rep(j,n)ans[i][j]='-';
	rep(i,n)rep(j,n){
		if(x[i][j]==i && y[i][j]==j){
			ans[i][j]='X';
			q.emplace(i,j);
		}
	}
	while(q.size()){
		auto p = q.front();q.pop();
		int cx = p.first, cy = p.second;
		rep(i,4){
			int nx = cx+d[i],ny=cy+d[i+1];
			if(nx<0||nx>=n||ny<0||ny>=n||ans[nx][ny]!='-')continue;
			if(x[nx][ny]==x[cx][cy] && y[nx][ny]==y[cx][cy]){
				ans[nx][ny]=ac[i];
				q.emplace(nx,ny);
			}
		}
	}
	rep(i,n)rep(j,n){
		if(x[i][j]!=-2 && ans[i][j]=='-'){
			cout<<"INVALID"<<endl;
			return 0;
		}
		if(x[i][j]==-2){
			rep(k,4){
				int nx = i+d[k],ny=j+d[k+1];
				if(nx<0||nx>=n||ny<0||ny>=n)continue;
				if(x[nx][ny]==-2){
					ans[i][j]=ac[k^2];
				}
			}
			if(ans[i][j]=='-'){
				cout<<"INVALID"<<endl;
				return 0;
			}
		}
	}
	cout<<"VALID"<<endl;
	rep(i,n){
		rep(j,n)cout<<ans[i][j];
		cout<<'\n';
	}
	return 0;
}