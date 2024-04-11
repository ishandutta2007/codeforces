#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=25;
pii a[N];
int ans[N];
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)ans[a[i].second]=a[i-1].first;
	ans[a[1].second]=a[n].first;
	for(int i=1;i<=n;i++)printf("%i ",ans[i]);
	return 0;
}