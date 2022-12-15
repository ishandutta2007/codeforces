#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MN = 5005;
int N, i, a, b, x, ans=1<<30;
pii arr[MN]; map<int,int> mp, rev;
bitset<2*MN> can[MN];

void solve(int n,int p){
	if(n == N+1){
		ans=min(ans,rev[p]);
		return;
	}
	int a=mp[arr[n].first],b=mp[arr[n].second];
	if(p <= a) solve(n+1, a);
	else if(p <= b) solve(n+1, b);
}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d%d",&arr[i].second,&arr[i].first);
		mp[arr[i].first]=mp[arr[i].second]=0;
	}
	i=0; auto it = mp.begin();
	for(;it!=mp.end();it++)
		it->second=++i, rev[i]=it->first;
	sort(arr+1,arr+N+1,[](pii i,pii j){return i.second==j.second?i.first<j.first:i.second<j.second;});
	solve(1, 1);
	printf("%d\n",ans);
	return 0;
}