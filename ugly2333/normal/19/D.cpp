//CF 19D_2
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
const int N = 222222;
const int inf = 2e9;
int n,m,qw[N],qx[N],qy[N];
pair<int,int> p[N];
int T[N<<3];
void add(int x,int y,int k=1,int l=1,int r=m){
	if(l==r){
		T[k]=y;
		return;
	}
	int e=l+r>>1;
	if(x<=e)
		add(x,y,k<<1,l,e);
	else
		add(x,y,k<<1|1,e+1,r);
	T[k]=max(T[k<<1],T[k<<1|1]);
}
void rem(int x,int k=1,int l=1,int r=m){
	if(l==r){
		T[k]=0;
		return;
	}
	int e=l+r>>1;
	if(x<=e)
		rem(x,k<<1,l,e);
	else
		rem(x,k<<1|1,e+1,r);
	T[k]=max(T[k<<1],T[k<<1|1]);
}
int fnd(int x,int y,int k=1,int l=1,int r=m){
	if(r<=x)
		return inf;
	if(T[k]<=y)
		return inf;
	if(l==r)
		return l;
	int e=l+r>>1,res;
	res=fnd(x,y,k<<1,l,e);
	if(res!=inf)
		return res;
	return fnd(x,y,k<<1|1,e+1,r);
}
int main()
{
	int i,j,ans;
	char ch[11];
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s%d%d",ch,qx+i,qy+i);
		if(ch[0]=='a')
			qw[i]=1;
		if(ch[0]=='r')
			qw[i]=2;
		if(ch[0]=='f')
			qw[i]=3;
		p[i]=make_pair(qx[i],qy[i]);
	}
	sort(p+1,p+n+1);
	m=unique(p+1,p+n+1)-p-1;
	for(i=1;i<=n;i=i+1){
		if(qw[i]<3)
			j=lower_bound(p+1,p+m+1,make_pair(qx[i],qy[i]))-p;
		else
			j=upper_bound(p+1,p+m+1,make_pair(qx[i],inf))-p-1;
		if(qw[i]==1)
			add(j,qy[i]);
		if(qw[i]==2)
			rem(j);
		if(qw[i]==3){
			ans=fnd(j,qy[i]);
			if(ans==inf)
				cout<<-1<<endl;
			else
				cout<<p[ans].first<<' '<<p[ans].second<<endl;
		}
	}
	return 0;
}