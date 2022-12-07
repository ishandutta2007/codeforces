#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int cnt[15],a[15][N];
int b[N][15],id[N];
int re[15],idx[15],n,m,ans;

bool cmp(int x,int y){
	for (int i=1;i<=n;i++)
		if (b[x][i]!=b[y][i])
			return b[x][i]<b[y][i];
	return 0;
}
void updp(int x,int p,int v){
	int sum=0;
	for (int i=1;i<=n;i++){
		if (i<p) idx[i]=b[x][i];
		else idx[i]=(i==p?v:cnt[i]);
	 	sum+=a[i][idx[i]];
	}
	if (sum>ans){
		ans=sum;
		memcpy(re,idx,sizeof(int)*15);
	}
}
void upd(int x,int y){
	int p=1;
	for (;p<=n&&b[x][p]==b[y][p];++p);
	if (p>n) return;
	if (b[x][p]+1!=b[y][p])
		updp(x,p,b[y][p]-1);
	for (++p;p<=n;++p){
		if (b[x][p]!=cnt[p]) updp(x,p,cnt[p]);
		if (b[y][p]!=1) updp(y,p,b[y][p]-1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&cnt[i]);
		for (int j=1;j<=cnt[i];j++)
			scanf("%d",&a[i][j]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&b[i][j]);
	for (int j=2;j<=n;j++){
		b[m+1][j]=cnt[j];
		b[m+2][j]=1;
	}
	b[m+1][1]=0;
	b[m+2][1]=cnt[1]+1;
	for (int i=1;i<=m+2;i++) id[i]=i;
	sort(id+1,id+m+3,cmp);
	for (int i=1;i<=m+1;i++) upd(id[i],id[i+1]);
	for (int i=1;i<=n;i++)
		printf("%d ",re[i]);
}