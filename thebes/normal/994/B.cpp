#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
struct pii{int first,second,id;}arr[MN];
int n, k, i, j; long long tot, ans[MN];
vector<int> idk;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
		scanf("%d",&arr[i].first);
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i].second);
	for(i=1;i<=n;i++) arr[i].id=i;
	sort(arr+1,arr+n+1,[](pii i,pii j){return i.first<j.first;});
	for(i=1;i<=n;i++){
		tot = 0;
		for(j=1;j<=min((int)idk.size(),k);j++)
			tot += idk[idk.size()-j];
		ans[arr[i].id]=tot+arr[i].second;
		int p=lower_bound(idk.begin(),idk.end(),arr[i].second)-idk.begin();
		if(p==idk.size()) idk.push_back(arr[i].second);
		else idk.insert(idk.begin()+p,arr[i].second);
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	return 0;
}