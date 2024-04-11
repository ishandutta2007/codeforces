#include<bits/stdc++.h>
using namespace std;

int n,p[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++) p[i]=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[x]=i;
	}
	int ans=0;
	for (int i=1;i<=2*n;i++)
		for (int j=i+1;1ll*j*i<=2*n;j++)
			if (p[i]&&p[j]&&p[i]+p[j]==i*j)
				ans++;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}