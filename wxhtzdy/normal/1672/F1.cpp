#include <bits/stdc++.h>
using namespace std;

const int N=200050;
int n,a[N],b[N],ord[N];
void Solve(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),ord[i]=i;
	sort(ord+1,ord+n+1,[&](int i,int j){return a[i]<a[j];});
	map<int,int> cnt;
	int mx=0;
	for(int i=1;i<=n;i++)cnt[a[i]]++,mx=max(mx,cnt[a[i]]);
	for(int i=1;i<=n;i++)b[ord[i]]=a[ord[(i+mx-1)%n+1]];
	for(int i=1;i<=n;i++)printf("%i ",b[i]);
	printf("\n");
}

int main(){
	int t;scanf("%i",&t);
	while(t--)Solve();
	return 0;
}