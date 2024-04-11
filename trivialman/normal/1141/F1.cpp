#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 1510;

int n,x,s[N];
unordered_map<int, vector<pair<int,int> > > slr;

int main() {
	#ifndef ONLINE_JUDGE 
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);s[0]=0;
	rep(i,1,n)scanf("%d",&x),s[i]=s[i-1]+x;
	rep(l,1,n)rep(r,l,n)
		slr[s[r]-s[l-1]].PB(MP(r,l));
	vector<pair<int, int> > ans;
	for(auto &ele:slr){
		vector<pair<int,int>> lr = ele.second;
		sort(lr.begin(),lr.end());
		int nowr=-1;
		vector<pair<int, int> > tmp;
		for(auto x:lr)if(x.second>nowr){
			tmp.PB(x);nowr=x.first;
		}
		if(tmp.size()>ans.size()) ans = tmp;
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n", x.second, x.first);
}