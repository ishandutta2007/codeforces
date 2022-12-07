#include<bits/stdc++.h>

using namespace std;

int n;
int a[105];
void solve(){
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		++a[abs(x)];
	} 
	int ans=0;
	for (int i=0;i<=100;i++)
		ans+=min(1+(i!=0),a[i]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}