//  Created by  on 2018/8/24.

#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();signed char f = 1;
	while (!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}

ll n,m,cu,co,sc = 0,csttb[3030][3030];
vector<ll> cst[3030];
int main() {
	read(n);read(m);
	for(int i=0;i<n;i++){
		read(cu);read(co);
		cst[cu].push_back(co);
	}
	for(int i=1;i<=m;i++){
		sort(cst[i].begin(), cst[i].end());
		csttb[i][0] = 0;
		for(int j=0;j<cst[i].size();j++){
			csttb[i][j+1] = csttb[i][j]+cst[i][j];
		}
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int i=(int)cst[1].size();i<=n;i++){
		vector<ll> cc;
		ll rem = i-cst[1].size(),cans = 0,cb;
		for(int j=2;j<=m;j++){
			if(cst[j].size()>=i+rem)goto nxt;
			cb = 0;
			if(cst[j].size()>=i){
				cb = cst[j].size()-i+1;
				cans+=csttb[j][cst[j].size()-i+1];
				rem-=cb;
			}
			for(int i=cb;i<cst[j].size();i++)cc.push_back(cst[j][i]);
		}
		sort(cc.begin(),cc.end());
		//cout<<cans<<endl;
		//cout<<cc[0]<<endl;
		for(int i=0;i<rem;i++)cans+=cc[i];
		//cout<<i<<' '<<cans<<endl;
		ans = min(ans,cans);
	nxt:;
	}
	cout<<ans<<endl;
	return 0;
}