//CF1662F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 444444;
const int W = N<<5;
int n,ss,tt,p[N],l[N],r[N];
int tot,e1,e2,rt1[N],rt2[N],ls[W],rs[W],d[W];
vector<int> vl[N],vr[N];
queue<int> q;
void modify(int&k,int kk,int x,int l=1,int r=n){
	if(!k)
		k=++tot;
	if(l==r)
		return;
	int h=l+r>>1;
	if(x<=h)
		modify(ls[k],ls[kk],x,l,h),rs[k]=rs[kk];
	else
		modify(rs[k],rs[kk],x,h+1,r),ls[k]=ls[kk];
}
void query(int rt,int L,int R,int X,int l=1,int r=n){
	if(!rt||r<L||R<l||d[rt]<=X)
		return;//cout<<rt<<' '<<l<<' '<<r<<endl;
	if(L<=l&&r<=R)
		d[rt]=X;
	if(l==r){
		if(d[l]>X){
			d[l]=X;
			q.push(l);
		}
		return;
	}
	int h=l+r>>1;
	query(ls[rt],L,R,X,l,h);
	query(rs[rt],L,R,X,h+1,r);
}
int main()
{
	int T,i,j,x,u;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&ss,&tt);
		for(i=1;i<=n;i++){
			scanf("%d",p+i);
			l[i]=max(1,i-p[i]);
			r[i]=min(n,i+p[i]);
			vl[r[i]].push_back(i);
			vr[l[i]].push_back(i);
		}
		tot=n;
		e1=++tot;
		for(i=1;i<=n;i++){
			for(j=0;j<vr[i].size();j++){
				x=vr[i][j];
				u=0;
				modify(u,e1,x);
				e1=u;
			}
			rt1[i]=e1;
		}
		e2=++tot;
		for(i=n;i>=1;i--){
			for(j=0;j<vl[i].size();j++){
				x=vl[i][j];
				u=0;
				modify(u,e2,x);
				e2=u;
			}
			rt2[i]=e2;
		}
		for(i=1;i<=tot;i++)
			d[i]=N;
		d[ss]=0;
		q.push(ss);
		while(!q.empty()){
			i=q.front();
			q.pop();//cout<<i<<' '<<d[i]<<endl;
			query(rt1[i],i,r[i],d[i]+1);
			query(rt2[i],l[i],i,d[i]+1);
		}
		printf("%d\n",d[tt]);
		for(i=1;i<=tot;i++)
			ls[i]=0,rs[i]=0;
		for(i=1;i<=n;i++)
			vl[i].clear(),vr[i].clear();
	}
	return 0;
}