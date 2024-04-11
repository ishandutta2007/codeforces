#include<bits/stdc++.h>

using namespace std;

const int N=300005;
int n,m;
int a[N],q[N];
int cnt[N],id[N],wei[N];
vector<int> v[N];
vector<pair<int,int> > ban[805][805];

int clk,vis[N];
int F(int i,int j){
	int m=v[j].size();
	int n=v[i].size();
	int ans=-1,mxq=0;
	int r=ban[i][j].size()-1;
	for (int p=n-1;p>=0;p--){
		++clk;
		for (;r>=0&&ban[i][j][r].first==v[i][p];--r){
			int pl=lower_bound(v[j].begin(),v[j].end(),ban[i][j][r].second)-v[j].begin();
			vis[pl]=clk;
		} 
		int q=m-1;
		for (;q>=mxq&&vis[q]==clk;--q);
		mxq=max(mxq,q);
		if (q>=0) ans=max(ans,v[i][p]+v[j][q]);
		if (q==m-1) break;
	}
	/*cout<<"ANS "<<i<<' '<<j<<' '<<ans<<endl;
	for (auto p:v[i]) cout<<p<<' '; cout<<endl;
	for (auto q:v[j]) cout<<q<<' '; cout<<endl;*/
	return ans;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),q[i]=a[i];
	sort(q+1,q+n+1);
	*q=unique(q+1,q+n+1)-q-1;
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(q+1,q+*q+1,a[i])-q;
	for (int i=1;i<=*q;i++) cnt[i]=0;
	for (int i=1;i<=*q;i++) v[i].resize(0);
	for (int i=1;i<=n;i++) ++cnt[a[i]];
	for (int i=0;i<=n;i++) id[i]=0;
	for (int i=1;i<=*q;i++){
		if (!id[cnt[i]]){
			id[cnt[i]]=++*id;
			wei[*id]=cnt[i];
		}
		v[id[cnt[i]]].push_back(q[i]);
	}
	for (int i=1;i<=*id;i++)
		sort(v[i].begin(),v[i].end());
	for (int i=1;i<=*id;i++)
		for (int j=1;j<=*id;j++)
			ban[i][j].resize(0);
	for (int i=1;i<=*q;i++)
		ban[id[cnt[i]]][id[cnt[i]]].push_back(pair<int,int>(q[i],q[i]));
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int px=lower_bound(q+1,q+*q+1,x)-q;
		int py=lower_bound(q+1,q+*q+1,y)-q;
		int idx=id[cnt[px]];
		int idy=id[cnt[py]];
		ban[idx][idy].push_back(pair<int,int>(x,y));
		ban[idy][idx].push_back(pair<int,int>(y,x));
	}
	long long ans=0;
	for (int i=1;i<=*id;i++)
		for (int j=i;j<=*id;j++){
			sort(ban[i][j].begin(),ban[i][j].end());
			ans=max(ans,1ll*(wei[i]+wei[j])*F(i,j));
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}