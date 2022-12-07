#include<bits/stdc++.h>

using namespace std;

const int N=150005;
int vis[N][2];
int q[N*2][2];
int re1[5],re2[5];
vector<int> pr[N],nx[N];
int ptag[N],ntag[N],sp[N],sn[N]; 
int n,m;
void solve1(int l,int r){
	memset(re1,0,sizeof(re1));
	for (int i=0;i<=l;i++) vis[i][0]=vis[i][1]=0;
	int h=0,t=1;
	q[1][0]=l; q[1][1]=0; vis[l][0]=1;
	while (h!=t){
		int x=q[++h][0],y=q[h][1];
		for (auto i:pr[x+1])
			if (i!=x&&sp[l]==sp[i+1])
				if (!vis[i][y^1]){
					vis[i][y^1]=1;
					q[++t][0]=i;
					q[t][1]=y^1;
				}
	}
	for (int i=0;i<=l;i++){
		//cout<<i<<' '<<sp[i]<<' '<<vis[i][0]<<' '<<vis[i][1]<<endl;
		if (!sp[i]){
			int msk=vis[i][0]+vis[i][1]*2;
			++re1[msk];
		}
	}
}
void solve2(int l,int r){
	memset(re2,0,sizeof(re2));
	for (int i=l;i<=n;i++) vis[i][0]=vis[i][1]=0;
	int h=0,t=1;
	q[1][0]=l; q[1][1]=0; vis[l][0]=1;
	while (h!=t){
		int x=q[++h][0],y=q[h][1];
		for (auto i:nx[x])
			if (i!=x+1&&sn[i-2]==sn[x])
				if (!vis[i-1][y^1]){
					vis[i-1][y^1]=1;
					q[++t][0]=i-1;
					q[t][1]=y^1;
				}
	}
	for (int i=l;i<=n;i++){
		//cout<<i<<' '<<sn[n]-sn[i]<<' '<<vis[i][0]<<' '<<vis[i][1]<<endl;
		if (sn[i]==sn[n]){
			int msk=vis[i][0]+vis[i][1]*2;
			++re2[msk];
		}
	}
}
/*
0:(l,l+1)
1:(l+1,l);
*/
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n+1;i++){
		pr[i].resize(0);
		nx[i].resize(0);
		ptag[i]=ntag[i]=0;
	}
	ntag[0]=ntag[n]=1;
	ptag[1]=ptag[n+1]=1;
	for (int i=1;i<=n;i++){
		nx[0].push_back(i);
		pr[i].push_back(0);
		nx[i].push_back(n+1);
		pr[n+1].push_back(i);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x+1==y) ntag[x]=ptag[y]=1;
		pr[y].push_back(x);
		nx[x].push_back(y);
	}
	int l=1,r=n;
	for (;ntag[l];++l);
	for (;ptag[r];--r);
	for (int i=1;i<=n+1;i++){
		sn[i]=sn[i-1]+1-ntag[i];
		sp[i]=sp[i-1]+1-ptag[i];
	}
	if (l==n+1){
		printf("%lld\n",1ll*n*(n-1)/2);
		return;
	}
	//cout<<l<<' '<<r<<endl;
	solve1(l,r);
	solve2(l,r);
	long long ans=0;
	for (int i=0;i<=3;i++)
		for (int j=0;j<=3;j++)
			if (i&j) ans+=1ll*re1[i]*re2[j];
	if (l+1==r) --ans;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}