#include<bits/stdc++.h>
using namespace std;

int m,k,mx,a[100005];
int ans[805][805];
int id[100005];
bool check(int mid){
	int A=mid-mid/2,B=mid/2;
	if (m>A*A+A*B+B*A) return 0;
	if (mx>A*A+A*B) return 0;
	return 1;
}
priority_queue<pair<int,int> > Q;
bool cmp(int x,int y){
	return a[x]>a[y];
}
void con(int n){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans[i][j]=0;
	for (;!Q.empty();Q.pop());
	for (int i=1;i<=k;i++)
		Q.push(pair<int,int>(a[i],i));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i%2==1&&j%2==1){
				int k=Q.top().second;
				if (!a[k]) break;
				Q.pop();
				--a[k];
				ans[i][j]=k;
				Q.push(pair<int,int>(a[k],k));
			}
	for (int i=1;i<=k;i++)
		id[i]=i;
	sort(id+1,id+k+1,cmp);
	int p=1;
	if (n%2==0){
	for (int i=1;i<=n;i++)
		for (int j=n;j>=1;j--)
			if (i%2==0&&j%2==1){
				for (;p<=k&&!a[id[p]];++p);
				ans[i][j]=(p>k?0:id[p]);
				--a[id[p]];
			}
	for (int i=1;i<=n;i++)
		for (int j=n;j>=1;j--)
			if (i%2==1&&j%2==0){
				for (;p<=k&&!a[id[p]];++p);
				ans[i][j]=(p>k?0:id[p]);
				--a[id[p]];
			}
	}
	else{
	for (int i=1;i<=n;i++)
		for (int j=n;j>=1;j--)
			if (i%2==1&&j%2==0){
				for (;p<=k&&!a[id[p]];++p);
				ans[i][j]=(p>k?0:id[p]);
				--a[id[p]];
			}
	for (int i=1;i<=n;i++)
		for (int j=n;j>=1;j--)
			if (i%2==0&&j%2==1){
				for (;p<=k&&!a[id[p]];++p);
				ans[i][j]=(p>k?0:id[p]);
				--a[id[p]];
			}
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
}
void solve(){
	mx=0;
	scanf("%d%d",&m,&k);
	for (int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	int l=1,r=800,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	con(ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
 b b
a a a
 b b
a a a
 b b
*/