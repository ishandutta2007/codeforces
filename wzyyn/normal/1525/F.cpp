#include<bits/stdc++.h>
using namespace std;

const int N=55;
int n,m,k,ans,e[N][N];
int vis[N],matx[N],maty[N];
int cmatx[N],cmaty[N];
int banx[N],bany[N],q[N];
long long f[N][N];
int fr[N][N],a[N],b[N];
bool dfs(int x){
	for (int i=1;i<=n;i++)
		if (!vis[i]&&e[x][i]&&!bany[i]){
			vis[i]=1;
			if (!maty[i]||dfs(maty[i])){
				maty[i]=x;
				matx[x]=i;
				return 1;
			}
		}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=1;
	}
	for (int i=1;i<=k;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if (dfs(i)) ++ans;
	}
	int nans=ans;
	for (;ans+k>=n;){
		memcpy(cmatx,matx,sizeof(matx));
		memcpy(cmaty,maty,sizeof(maty));
		for (int i=1;i<=n;i++)
			if (cmatx[i]){
				//cout<<i<<' '<<cmatx[i]<<' '<<ans<<endl;
				memcpy(matx,cmatx,sizeof(matx));
				memcpy(maty,cmaty,sizeof(maty));
				banx[i]=1;
				maty[matx[i]]=0;
				matx[i]=0;
				bool flag=0;
				for (int j=1;j<=n;j++)
					if (!matx[j]&&!banx[j]){
						memset(vis,0,sizeof(vis));
						if (dfs(j)){
							flag=1;
							break;
						}
					}
				if (!flag){
					q[++*q]=i;
					break;
				}
				banx[i]=0;
				flag=0;
				memcpy(matx,cmatx,sizeof(matx));
				memcpy(maty,cmaty,sizeof(maty));
				bany[matx[i]]=1;
				maty[matx[i]]=0;
				matx[i]=0;
				for (int j=1;j<=n;j++)
					if (!matx[j]&&!banx[j]){
						memset(vis,0,sizeof(vis));
						if (dfs(j)){
							flag=1;
							break;
						}
					}
				if (!flag){
					q[++*q]=-cmatx[i];
					break;
				}
				bany[cmatx[i]]=0;
			}
		--ans;
	}
	
	memset(f,233,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=k;i++)
		for (int l=0;l<=*q;l++)
			for (int r=l;r<=*q;r++)
				if (i+(nans-r)<n)
					if (f[i][r]<f[i-1][l]+max(0ll,a[i]-1ll*(r-l)*b[i])){
						f[i][r]=f[i-1][l]+max(0ll,a[i]-1ll*(r-l)*b[i]);
						fr[i][r]=l;
					}
	vector<int> res;
	for (int i=k,p=*q;i>0;i--){
		res.push_back(0);
		for (int j=fr[i][p]+1;j<=p;j++)
			res.push_back(q[j]);
		p=fr[i][p];
	}
	reverse(res.begin(),res.end());
	printf("%d\n",res.size());
	for (auto i:res) printf("%d ",i);
}