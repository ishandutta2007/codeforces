//CF 911G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 2e5+25;;
const int A = 100;
int n,a[N],T[N<<2][A+5];
int q,qx[N],qy[N];
vector<int> v[N];
void upd(int k,int x,int y){
	for(int j=1;j<=A;j=j+1)
		T[k][j]=T[y][T[x][j]];
}
void build(int k=1,int l=1,int r=q){
	for(int j=1;j<=A;j=j+1)
		T[k][j]=j;
	if(l==r-1)
		return;
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h,r);
}
void modify(int p,int x,int y,int k=1,int l=1,int r=q){
	if(l==r-1){
		T[k][x]=y;
		return;
	}
	int h=l+r>>1;
	if(p<h)
		modify(p,x,y,k<<1,l,h);
	else
		modify(p,x,y,k<<1|1,h,r);
	upd(k,k<<1,k<<1|1);
}
int main()
{
	int i,x,y,s,h;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	scanf("%d",&q);
	q++;
	build();
	for(i=1;i<q;i=i+1){
		scanf("%d%d%d%d",&x,&y,qx+i,qy+i);
		v[x].push_back(i);
		v[y+1].push_back(-i);
	}
	for(i=1;i<=n;i=i+1){
		s=v[i].size();
		while(s--){
			h=v[i][s];
			if(h>0)
				x=qx[h],y=qy[h];
			else
				h=-h,x=qx[h],y=x;
			modify(h,x,y);
		}
		cout<<T[1][a[i]]<<' ';
	}
	return 0;
}