#include"bits/stdc++.h"
typedef long long ll;
using namespace std;
const int N=1005;
int n,mn[N],GET[N],f[2][N][N],cnt[2][N]; bool mk[N];
void solve(int l,int r,int dep){
	int mid=(l+r)/2;if(l==r)return;
	solve(l,mid,dep+1);solve(mid+1,r,dep+1);
	for(int i=l;i<=mid;i++)f[0][dep][++cnt[0][dep]]=i;
	for(int i=mid+1;i<=r;i++)f[1][dep][++cnt[1][dep]]=i;
}
void work(int l,int r,int dep){
	int mid=(l+r)/2;if(l==r)return;
	for (int i=0;i<2;i++){
		if(cnt[i][dep]==0) continue;
		memset(mk,0,sizeof(mk));
		printf("%d\n",cnt[i][dep]); fflush(stdout);
		for (int j=1;j<cnt[i][dep];j++)
			printf("%d ",f[i][dep][j]),mk[f[i][dep][j]]=1;
		printf("%d\n",f[i][dep][cnt[i][dep]]); fflush(stdout);
		mk[f[i][dep][cnt[i][dep]]]=1;
		for (int j=1;j<=n;j++){
			scanf("%d",&GET[j]);
			if(!mk[j])mn[j]=min(mn[j],GET[j]);
		}
	}
	work(l,mid,dep+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)mn[i]=(int)1e9;
	solve(1,n,1); work(1,n,1);
	printf("-1\n");fflush(stdout);
	for(int i=1;i<n;i++)
		printf("%d ",mn[i]);
	printf("%d\n",mn[n]);
	fflush(stdout); 
	return 0;
}