#include <bits/stdc++.h>
using namespace std;

int n, i, j, x, arr[1005];
vector<int> ans;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=n;i=j){
		for(j=i;j<=n&&arr[j]-arr[i]==j-i;j++){}
		ans.push_back(j-i);
	}
	printf("%d\n",ans.size());
	for(auto v : ans) printf("%d ",v);
	getchar(); getchar();
}