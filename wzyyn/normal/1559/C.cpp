#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n,a[10005];
void Con(int x){
	for (int i=1;i<=x;i++) printf("%d ",i);
	printf("%d ",n+1);
	for (int i=x+1;i<=n;i++) printf("%d ",i);
	puts("");
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (a[1]==1) Con(0);
	else if (a[n]==0) Con(n);
	else{
		for (int i=1;i<n;i++)
			if (a[i]==0&&a[i+1]==1){
				Con(i); break;
		}
	} 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}