//E
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
const int N = 4e5+5;
int l[N],r[N],p[N];
pair<int,int> a[N];
vector<pair<int,int> > v[N];
int T[4*N],ans[N];
void build(int k,int l,int r)
{
	if(l==r){
		T[k]=p[l];
		return;
	}
	int md;
	md=(l+r)/2;
	build(k<<1,l,md);
	build(k<<1|1,md+1,r);
	T[k]=T[k<<1]+T[k<<1|1];
}
void modify(int k,int l,int r,int L,int R){
	if(l==L&&r==R||!T[k]){
		T[k]=0;
		return;
	}
	int md;
	md=(l+r)/2;
	if(L<=md)
		modify(k<<1,l,md,L,min(md,R));
	if(md+1<=R)
		modify(k<<1|1,md+1,r,max(L,md+1),R);
	T[k]=T[k<<1]+T[k<<1|1];
}
int query(int k,int l,int r,int L,int R){
	//cout<<k<<l<<r<<L<<R<<T[k]<<endl;
	if(T[k]==0)
		return 0;
	if(l==L&&r==R)
		return T[k];
	int md,res;
	md=(l+r)/2;
	res=0;
	if(L<=md)
		res+=query(k<<1,l,md,L,min(md,R));
	if(md+1<=R)
		res+=query(k<<1|1,md+1,r,max(L,md+1),R);
	return res;
}
int main()
{
	int n,q,i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		l[i]=x;
		r[i]=x+y;
		a[2*i]=make_pair(l[i],2*i);
		a[2*i+1]=make_pair(r[i],2*i+1);
	}
	
	sort(a+2,a+2*n+2);
	for(i=2;i<=2*n+1;i=i+1){
		x=a[i].second;
		if(x&1)
			r[x/2]=i;
		else
			l[x/2]=i;
		if(i==2*n+1)
			p[i]=0;
		else
			p[i]=a[i+1].first-a[i].first;
		//cout<<p[i]<<' ';
	}
	
	//cout<<endl;
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
	}
	build(1,2,2*n+1);
	//for(i=1;i<=n;i=i+1)
	//	cout<<l[i]<<r[i]<<query(1,2,2*n+1,l[i],r[i]-1)<<endl;
	for(i=n;i>=1;i=i-1){
		modify(1,2,2*n+1,l[i],r[i]-1);
		//cout<<query(1,2,13,2,13)<<endl;
		y=v[i].size();
		for(x=0;x<y;x=x+1)
			ans[v[i][x].second]=query(1,2,2*n+1,r[i],l[v[i][x].first]-1);
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}
/*
6
1 5
3 3
4 4 
9 2
10 1
12 1
4
1 2
2 4
2 5
2 6

*/