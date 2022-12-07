#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=200005;
int n,m,a[N];
pair<int,int> b[N];
long long f[5],g[5];
vector<pair<int,int>> op[N];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&b[i].fi,&b[i].se);
		int p=lower_bound(a+1,a+n+1,b[i].fi)-a;
		if (p<=n&&a[p]<=b[i].se) i--,m--;
	}
	if (m==0){
		cout<<0<<endl;
		return;
	}
	sort(b+1,b+m+1);
	int t=1;
	for (int i=2;i<=m;i++){
		for (;t&&b[i].se<b[t].se;--t);
		if (!t||b[i].fi>b[t].fi) b[++t]=b[i];
	}
	m=t;
	//for (int i=1;i<=m;i++)
	//	cout<<"RANGE "<<b[i].fi<<' '<<b[i].se<<endl;
	for (int i=1;i<=n+1;i++) op[i].resize(0);
	for (int i=1;i<=m;i++){
		int p=lower_bound(a+1,a+n+1,b[i].fi)-a;
		op[p].push_back(b[i]);
	}
	int cl=(op[1].size()?a[1]-op[1][0].second:0);
	f[1]=cl; f[2]=2ll*cl;
	for (int i=1;i<n;i++){
		g[1]=1ll<<60;
		g[2]=1ll<<60;
		for (int j=0;j<=op[i+1].size();j++){
			int cl=(j==0?0:op[i+1][j-1].first-a[i]);
			int cr=(j==op[i+1].size()?0:a[i+1]-op[i+1][j].second);
			g[1]=min(g[1],cr+min(f[1]+2ll*cl,f[2]+cl));
			g[2]=min(g[2],2*cr+min(f[1]+2ll*cl,f[2]+cl));
		}
		f[1]=g[1]; f[2]=g[2];
	}
	int cr=(op[n+1].size()?op[n+1].back().first-a[n]:0);
	printf("%lld\n",min(f[1]+2ll*cr,f[2]+cr));
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}