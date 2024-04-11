#include<bits/stdc++.h>

using namespace std;

char s[2005];
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	int ans=1,f=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			if (s[j]=='#') ans=2*ans%1000000007;
			else f=1;
	}
	if (!f) ans--;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}