#include<bits/stdc++.h>
using namespace std;

int n,m;
int ax[20],ay[20];
int bx[205],by[205],t[205];
int mnd[(1<<14)|5][205];
int f[105][(1<<14)|5];
int g[105][(1<<14)|5];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d%d",&ax[i],&ay[i]);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&bx[i],&by[i],&t[i]);
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (t[i]>t[j]){
				swap(t[i],t[j]);
				swap(bx[i],bx[j]);
				swap(by[i],by[j]);
			}
	for (int i=0;i<1<<n;i++)
		for (int k=1;k<=m;k++){
			mnd[i][k]=1<<28;
			for (int j=0;j<n;j++)
				if (i&(1<<j))
					mnd[i][k]=min(mnd[i][k],abs(ax[j]-bx[k])+abs(ay[j]-by[k]));
		}
	memset(f,65,sizeof(f));
	memset(g,233,sizeof(g));
	for (int i=0;i<n;i++)
		f[0][1<<i]=0;
	for (int i=1;i<=m;i++)
		g[i][0]=1;
	for (int j=0;j<1<<n;j++){
		int loc=1;
		for (int i=0;i<=m;i++){
			bool flag=(f[i][j]>=(1<<30));
			for (int k=i+1;k<=m;k++)
				if (f[i][j]>=f[k][j]) flag=1;
			if (flag) continue;
			for (;loc<=m&&t[loc]<=f[i][j];++loc){
				int ni=loc;
				if (g[ni][j]>=0){
					f[g[ni][j]][j]=min(f[g[ni][j]][j],t[ni]);
					for (int k=0;k<n;k++)
						if (!(j&(1<<k))){
							int mnd=abs(ax[k]-bx[ni])+abs(ay[k]-by[ni]);
							f[g[ni][j]][j|(1<<k)]=min(f[g[ni][j]][j|(1<<k)],t[ni]+mnd);
						}
					for (int k=ni+1;k<=m;k++){
						int mnd=abs(bx[ni]-bx[k])+abs(by[ni]-by[k]);
						if (t[ni]+mnd<=t[k])
							g[k][j]=max(g[k][j],g[ni][j]+1);
					}
				}
			}
			for (int k=0;k<n;k++)
				if (!(j&(1<<k))){
					int mnd=1<<28;
					for (int p=0;p<n;p++) if (j&(1<<p))
						mnd=min(mnd,abs(ax[k]-ax[p])+abs(ay[k]-ay[p]));
					f[i][j|(1<<k)]=min(f[i][j|(1<<k)],f[i][j]+mnd);
				}
			for (int p=1;p<=m;p++)
				if (f[i][j]+mnd[j][p]<=t[p])
					g[p][j]=max(g[p][j],i+1);
		}
		for (;loc<=m;++loc){
			int ni=loc;
			if (g[ni][j]>=0){
				f[g[ni][j]][j]=min(f[g[ni][j]][j],t[j]);
				for (int k=0;k<n;k++)
					if (!(j&(1<<k))){
						int mnd=abs(ax[k]-bx[ni])+abs(ay[k]-by[ni]);
						f[g[ni][j]][j|(1<<k)]=min(f[g[ni][j]][j|(1<<k)],t[ni]+mnd);
					}
				for (int k=ni+1;k<=m;k++){
					int mnd=abs(bx[ni]-bx[k])+abs(by[ni]-by[k]);
					if (t[ni]+mnd<=t[k])
						g[k][j]=max(g[k][j],g[ni][j]+1);
				}
			}
		}
		//for (int i=1;i<=m;i++)
		//	cout<<"G: "<<i<<' '<<j<<' '<<g[i][j]<<endl;
		//for (int i=0;i<=m;i++)
		//	cout<<"F: "<<i<<' '<<j<<' '<<f[i][j]<<endl;
	}
	int ans=0;
	for (int i=1;i<=m;i++)
		for (int j=0;j<1<<n;j++)
			ans=max(ans,g[i][j]);
	cout<<ans<<endl;
}
/*
2^14 * 100
f[i][j]: i  j 
g[i][j]: i,  j 

f->f:100*2^14*14^2
g->g:100*2^14*100
g->f:100*2^14*14
f->g:100*2^14*14*
*/