#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5;
int n, k, i, x, tot; map<int,int> mp;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
		scanf("%d",&x), mp[x]++;
	mp[1]=mp[1];
	for(auto v : mp){
		tot += v.second;
		if(tot==k){printf("%d\n",v.first);return 0;}
		else if(tot>k){printf("-1\n");return 0;}
	}
	printf("-1\n");
	return 0;
}