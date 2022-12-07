#include<bits/stdc++.h>
using namespace std;
const int N=1<<20|5;
int n,k,x;
int mn[N],mx[N],t[N],fl[N];
int ans[N],sz[N];
void pushup(int k){
	int ls=k*2+fl[k],rs=k*2+1-fl[k];
	mn[k]=min(mn[ls],mn[rs]+sz[k]/2);
	mx[k]=max(mx[ls],mx[rs]+sz[k]/2);
	t[k]=min(t[ls],t[rs]);
	if (mx[ls]>=0&&mn[rs]<=sz[k]) t[k]=min(t[k],sz[k]/2-mx[ls]+mn[rs]);
}
int main(){
	scanf("%d%d",&n,&k);
	memset(t,1,sizeof(t));
	memset(mn,1,sizeof(mn));
	memset(mx,254,sizeof(mx));
	for (int d=1;d<1<<k;d<<=1)
		for (int i=0;i<d;i++) sz[i+d]=(1<<k)/d;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		int y=x+(1<<k); mn[y]=mx[y]=0;
		for (y>>=1;y;y>>=1) pushup(y);
	}
	ans[x=0]=t[1];
	for (int i=1;i<1<<k;i++){
		int v=i^(i-1);
		for (;v!=(v&(-v));v-=v&(-v));
		for (int j=2*v-1;j>=v;j--) fl[j]^=1,pushup(j);
		for (int j=v-1;j>=1;j--) pushup(j);
		x^=(1<<k)/v/2; ans[x]=t[1];
	}
	for (int i=0;i<1<<k;i++)
		printf("%d ",ans[i]);
}