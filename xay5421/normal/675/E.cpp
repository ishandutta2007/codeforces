#include<cstdio>
typedef long long ll;const int N=100005,K=20;
int n,a[N],st[N][K],lg[N];ll ans,dp[N];
int query(int l,int r){
	int x=lg[r-l+1];int y=st[l][x],z=st[r-(1<<x)+1][x];
	return a[y]<a[z]?z:y;
}
int main(){
	scanf("%d",&n);for(int i=1;i<n;++i)scanf("%d",a+i),st[i][0]=i;for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;a[n]=n,st[n][0]=n;
	for(int j=1;j<K;++j)
		for(int i=1;i+(1<<j)-1<=n;++i){
			int x=st[i][j-1],y=st[i+(1<<j-1)][j-1];
			st[i][j]=(a[x]<a[y]?y:x);
		}
	for(int i=n-1;i>=0;--i){
		int pos=query(i+1,a[i]);
		dp[i]=dp[pos]-(a[i]-pos)+n-i;
	}
	for(int i=1;i<=n;++i)ans+=dp[i];
	printf("%I64d\n",ans);
	return 0;
}