#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
#define VPII vector<pair<int,int>>

int n,x,s[1510];
unordered_map<int, VPII> slr;

int main() {
	scanf("%d",&n);s[0]=0;
	rep(i,1,n)scanf("%d",&x),s[i]=s[i-1]+x;
	rep(r,1,n)rep(l,1,r)
		slr[s[r]-s[l-1]].PB(MP(r,l));
	VPII ans;
	for(auto &ele:slr){
		VPII lr = ele.second;
		int nowr=-1;
		VPII tmp;
		for(auto x:lr)if(x.second>nowr){
			tmp.PB(x);nowr=x.first;
		}
		if(tmp.size()>ans.size()) ans = tmp;
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n", x.second, x.first);
}