#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],flag[N],f[N],v[N],pp[N],to[N];
map<int,int> Map;
int cmp(int x,int y){
	return flag[x]>flag[y];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j*j<=i;j++)
			if (i%j==0)pp[i]=j;
	int cnt=0;		
	for (int i=1;i<=n;i++){
		if (!Map[a[i]])Map[a[i]]=++cnt,to[Map[a[i]]]=a[i];
		flag[Map[a[i]]]++;
	}
	for (int i=1;i<=cnt;i++)v[flag[i]]++;
	for (int i=n;i>=1;i--)v[i]+=v[i+1];
	for (int i=1;i<=n;i++)v[i]+=v[i-1];
	int ans=0;
	for (int i=1;i<=n;i++)
		if (v[pp[i]]>=i)ans=i;
	printf("%d\n",ans);
	printf("%d %d\n",pp[ans],ans/pp[ans]);
	int A[pp[ans]][ans/pp[ans]];
	int nowx=0,nowy=0,l=pp[ans],r=ans/pp[ans];
	memset(A,0,sizeof A);
	for (int i=1;i<=cnt;i++)f[i]=i;
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=cnt;i++){
		int c=min(ans,min(l,flag[f[i]]));
		for (int j=0;j<c;j++){
			A[nowx][nowy]=to[f[i]];
			(nowx+=1)%=l;(nowy+=1)%=r;
			if (A[nowx][nowy])(nowy+=1)%=r;
		}
		ans-=c;
	}
	for (int i=0;i<l;i++){
		for (int j=0;j<r;j++)printf("%d ",A[i][j]);
		puts("");
	}
}