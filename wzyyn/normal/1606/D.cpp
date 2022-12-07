#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int n,m;
vector<int> v[N],pmn[N],pmx[N];
vector<int> smn[N],smx[N];
int val[N],id[N],tg[N];
int mnv[N],mxv[N];
bool cmp(int x,int y){
	return val[x]<val[y];
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		v[i].resize(0);
		pmn[i].resize(0);
		pmx[i].resize(0);
		smn[i].resize(0);
		smx[i].resize(0);
		for (int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
			pmn[i].push_back(x);
			pmx[i].push_back(x);
			smn[i].push_back(x);
			smx[i].push_back(x);
		}
		for (int j=1;j<m;j++){
			pmn[i][j]=min(pmn[i][j],pmn[i][j-1]);
			pmx[i][j]=max(pmx[i][j],pmx[i][j-1]);
		}
		for (int j=m-2;j>=0;j--){
			smn[i][j]=min(smn[i][j],smn[i][j+1]);
			smx[i][j]=max(smx[i][j],smx[i][j+1]);
		}
	}
	for (int j=1;j<m;j++){
		int mn=1<<30,mx=-1;
		for (int i=1;i<=n;i++) val[i]=pmx[i][j-1],id[i]=i;
		sort(id+1,id+n+1,cmp);
		for (int i=1;i<=n;i++){
			mnv[i]=pmn[id[i]][j-1];
			mxv[i]=smx[id[i]][j];
		}
		for (int i=n-1;i>=1;i--){
			mnv[i]=min(mnv[i],mnv[i+1]);
			mxv[i]=max(mxv[i],mxv[i+1]);
		}
		for (int i=1;i<=n;i++) tg[i]=1;
		for (int i=1;i<n;i++){
			tg[id[i]]=0;
			mn=min(mn,smn[id[i]][j]);
			mx=max(mx,pmx[id[i]][j-1]);
			if (mn>mxv[i+1]&&mx<mnv[i+1]){
				puts("YES");
				for (int p=1;p<=n;p++)
					putchar(tg[p]?'R':'B');
				printf(" %d\n",j);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}