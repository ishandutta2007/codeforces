#include<bits/stdc++.h>

using namespace std;

int n,a[105];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=1<<30;
	for (int s1=0;s1<=2;s1++)
		for (int s2=0;s2<=2;s2++){
			int mn[3]={0,1<<30,1<<30};
			int mx[3]={0,0,0};
			for (int p1=0;p1<=s1;p1++)
				for (int p2=0;p2<=s2;p2++){
					int v=p1*1+p2*2;
					mn[v%3]=min(mn[v%3],v);
					mx[v%3]=max(mx[v%3],v);
				}
			int v=0;
			for (int i=1;i<=n;i++){
				if (a[i]<mn[a[i]%3]) v=max(v,1<<30);
				else if (a[i]>mx[a[i]%3]) v=max(v,(a[i]-mx[a[i]%3])/3);
			}
			ans=min(ans,v+s1+s2);
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}