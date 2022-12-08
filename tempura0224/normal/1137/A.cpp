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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	vector<int> h[n],w[m];
	rep(i,n)rep(j,m){
		cin>>a[i][j];
		h[i].push_back(a[i][j]);
		w[j].push_back(a[i][j]);
	}
	rep(i,n){
		sort(h[i].begin(),h[i].end());
		h[i].erase(unique(h[i].begin(), h[i].end()),h[i].end());
	}
	rep(i,m){
		sort(w[i].begin(),w[i].end());
		w[i].erase(unique(w[i].begin(), w[i].end()),w[i].end());
	}

	rep(i,n){
		rep(j,m){
		int idx1=lower_bound(h[i].begin(),h[i].end(),a[i][j])-h[i].begin();
		int idx2=lower_bound(w[j].begin(),w[j].end(),a[i][j])-w[j].begin();
		int res=max(idx1,idx2)+max((int)h[i].size()-idx1,(int)w[j].size()-idx2);
		printf("%d ",res);
		}
		printf("\n");
	}
	return 0;
}