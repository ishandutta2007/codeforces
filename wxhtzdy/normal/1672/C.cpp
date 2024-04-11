#include <bits/stdc++.h>
using namespace std;

const int N=200050;
int n,a[N];
void solve(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	int l=n,r=0;
	for(int i=1;i<n;i++)if(a[i]==a[i+1])l=min(l,i),r=max(r,i);
	if(l>=r)printf("0\n");
	else printf("%i\n",max(1,r-l-1));
}

int main(){
	int t;scanf("%i",&t);
	while(t--)solve();
	return 0;
}