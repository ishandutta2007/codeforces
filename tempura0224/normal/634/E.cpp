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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[202020];
int a[202020];
pair<int,int> ma[202020];
int cnt[202020], ans[202020];
void marge(pair<int,int>& p, int x){
	if(x>=p.first){
		p.second = p.first;
		p.first = x;
	}
	else if(x>=p.second){
		p.second = x;
	}
}
pair<int,int> dfs(int x, int p){
	cnt[x]=0;
	ma[x]={0,0};
	if(!a[x]){
		for(auto to : v[x]){
			if(to==p)continue;
			dfs(to,x);
		}
		cnt[x]=1;
		ans[x]=0;
		return {0,1};
	}
	ans[x]=1;
	for(auto to : v[x]){
		if(to==p)continue;
		auto ret = dfs(to,x);
		if(ret.second){
			++cnt[x];
			marge(ma[x],ret.first);
		}
		else {
			ans[x]+=ret.first;
		}
	}
	return {ans[x]+ma[x].first, cnt[x]};
}

void rdfs(int x,int p){
	for(auto to : v[x]){
		if(to==p)continue;
		if(!a[x])++cnt[to];
		else if(cnt[to]){
			if(cnt[x]>=2){
				++cnt[to];
				if(ans[to]+ma[to].first==ma[x].first){
					marge(ma[to],ans[x]+ma[x].second);
				}
				else marge(ma[to],ans[x]+ma[x].first);
			}
			else {
				ans[to]+=ans[x];
			}
		}
		else {
			if(cnt[x])++cnt[to],marge(ma[to],ans[x]+ma[x].first-ans[to]);
			else ans[to]+=ans[x]-ans[to];
		}
	}
	for(auto to : v[x]){
		if(to==p)continue;
		rdfs(to,x);
	}
}

int main(){
	int n, k;
	cin>>n>>k;
	int b[n];
	rep(i,n)cin>>b[i];
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		--x;--y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ok =0, ng = 1000001;
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		rep(i,n)a[i]=(b[i]>=mid);
		dfs(0,-1);
		rdfs(0,-1);
		int ret = 0;
		rep(i,n)ret = max(ret,ans[i]+ma[i].first);
		if(ret>=k)ok=mid;
		else ng = mid;
	}
	cout<<ok<<endl;
	return 0;
}