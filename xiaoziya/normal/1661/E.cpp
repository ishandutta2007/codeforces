#include<stdio.h>
#include<iostream>
#include<vector>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=500005;
int n,m;
int a[4][maxn],sum[4][maxn],row[maxn],col[maxn],sqr[maxn],ans[maxn],xx[maxn],yy[maxn],t[maxn];
vector<int>v[maxn];
string s;
void update(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=v;
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=t[i];
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		cin>>s;
		int tot=0;
		for(int j=1;j<=n;j++){
			a[i][j]=s[j-1]=='1',sum[i][j]=sum[i][j-1]+a[i][j];
			tot+=a[i][j]&a[i][j-1],row[j]+=tot;
		}
	}
	for(int i=1;i<=n;i++){
		col[i]=col[i-1]+(a[1][i]&a[2][i])+(a[2][i]&a[3][i]);
		sqr[i]=sqr[i-1]+(a[1][i]&a[2][i]&a[1][i-1]&a[2][i-1])+(a[2][i]&a[3][i]&a[2][i-1]&a[3][i-1]);
	}
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),xx[i]=x,yy[i]=y,v[y].push_back(i);
		ans[i]=sum[1][y]-sum[1][x-1]+sum[2][y]-sum[2][x-1]+sum[3][y]-sum[3][x-1];
		ans[i]-=row[y]-row[x]+col[y]-col[x-1];
		ans[i]+=sqr[y]-sqr[x];
	}
	int lst=-1;
	for(int i=1;i<=n;i++){
		if(a[2][i]==1){
			if(lst!=-1&&lst+1<i&&sum[1][i]-sum[1][lst-1]==i-lst+1&&sum[3][i]-sum[3][lst-1]==i-lst+1)
				update(n-lst+1,1);
			lst=i;
		}
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ans[k]+=query(n-xx[k]+1);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}