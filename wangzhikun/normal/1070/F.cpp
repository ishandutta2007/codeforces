// Author : WangZhikun
// Date   : 2018-10-18
// ????????????????

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,m,q;
vector<int> a[4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int cid,cg;
		char cu[3];
		cin>>cu>>cg;
		cid = (cu[0]-'0')*2+(cu[1]-'0');
		a[cid].push_back(cg);
	}
	if(a[1].size()<a[2].size())swap(a[1],a[2]);
	for(int i=0;i<4;i++)sort(a[i].begin(),a[i].end());
	ll ans = 0,cc = a[3].size();
	while(a[3].size()){
		ans+=a[3][a[3].size()-1];
		a[3].pop_back();
	}
	while(a[2].size()){
		ans+=a[2][a[2].size()-1]+a[1][a[1].size()-1];
		a[2].pop_back();
		a[1].pop_back();
	}
	for(int i=0;i<a[1].size();i++){
		a[0].push_back(a[1][i]);
	}
	sort(a[0].begin(),a[0].end());
	while(cc && a[0].size()){
		--cc;
		ans+=a[0][a[0].size()-1];
		a[0].pop_back();
	}
	cout<<ans<<endl;
	return 0;
}