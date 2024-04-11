// CF 817F
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
int q[111111],T[444444];
bool t[444444];
LL x[111111],y[111111],p[222222];
pair<LL,int> a[222222];

void Modify(int l,int r,int v,int k,int ll,int rr)
{
	if(ll>rr||l>r||ll>l||r>rr)
		return;
	//cout<<l<<r<<k<<T[k]<<endl;
	if(ll==l&&rr==r){
		T[k]=v;
		t[k]=0;
		return;
	}
	int m;
	m=(ll+rr)/2;
	//t[k*2]^=t[k];
	//t[k*2+1]^=t[k];
	//t[k]=0;
	if(T[k]!=2){
		T[k*2]=T[k];
		T[k*2+1]=T[k];
		t[k]=0;
	}
	Modify(l,min(r,m),v^t[k],k*2,ll,m);
	Modify(max(l,m+1),r,v^t[k],k*2+1,m+1,rr);
	if(T[k*2]==2||T[k*2+1]==2||T[k*2]!=T[k*2+1])
		T[k]=2;
	else{
		T[k]=T[k*2]^t[k];
		t[k]=0;
	}
}
void modify(int l,int r,int k,int ll,int rr)
{
	if(ll>rr||l>r||ll>l||r>rr)
		return;
	if(ll==l&&rr==r){
		if(T[k]!=2)
			T[k]^=1;
		else
			t[k]^=1;
		return;
	}
	int m;
	m=(ll+rr)/2;
	if(T[k]!=2){
		T[k*2]=T[k];
		T[k*2+1]=T[k];
		t[k]=0;
	}
	modify(l,min(r,m),k*2,ll,m);
	modify(max(l,m+1),r,k*2+1,m+1,rr);
	if(T[k*2]==2||T[k*2+1]==2||T[k*2]!=T[k*2+1])
		T[k]=2;
	else{
		T[k]=T[k*2]^t[k];
		t[k]=0;
	}
}
int Query(int k,int ll,int rr,int f)
{
	if(ll>rr)
		return 1<<30;
	//cout<<k<<f<<T[k]<<ll<<endl;
	if((T[k]^f)==0)
		return ll;
	int m;
	m=(ll+rr)/2;
	if(T[k]!=2)
		t[k]=0;
	f^=t[k];
	if((T[k*2]^f)!=1)
		return Query(k*2,ll,m,f);
	return Query(k*2+1,m+1,rr,f);
}
int main()
{
	int n,i,j,o,ff;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>q[i]>>x[i]>>y[i];
		y[i]++;
		a[i]=make_pair(x[i],i);
		a[i+n]=make_pair(y[i],i+n);
	}
	sort(a+1,a+2*n+1);
	j=0;
	for(i=1;i<=2*n;i=i+1){
		if(a[i].first!=a[i-1].first)
			j++;
		p[j]=a[i].first;
		if(a[i].second>n)
			y[a[i].second-n]=j;
		else
			x[a[i].second]=j;
	}
	ff=0;
	if(a[1].first>1)
		ff=1;
	//cout<<j<<endl;
	for(i=1;i<=n;i=i+1){
		//cout<<x[i]<<' '<<y[i]-1<<endl;
		if(q[i]==1)
			Modify(x[i],y[i]-1,1,1,1,j);
		if(q[i]==2)
			Modify(x[i],y[i]-1,0,1,1,j);
		if(q[i]==3)
			modify(x[i],y[i]-1,1,1,j);
		if(ff){
			cout<<1<<endl;
			continue;
		}
		cout<<p[Query(1,1,j,0)]<<endl;
		/*for(o=1;o<=9;o=o+1)
			cout<<T[o]<<' ';
		cout<<endl;
		for(o=1;o<=9;o=o+1)
			cout<<t[o]<<' ';
		cout<<endl<<endl;*/
	}
	return 0;
}
/*
4
3 1 10
2 2 4
3 1 7
2 1 10

68
2 3 3
1 3 10
3 5 7
1 9 10
3 8 9
2 6 6
3 4 7
3 10 10
2 4 8
1 10 10
3 7 10
1 4 4
1 8 9
1 5 9
3 9 9
2 1 1
1 7 10
1 8 10
3 8 9
1 1 6
3 10 10
1 6 6
1 6 6
3 5 7
1 9 9
2 2 8
1 10 10
2 7 8
1 5 8
3 9 9
3 1 7
2 1 10
2 8 9
3 1 9
2 3 7
2 8 9
2 5 5
3 2 7
3 10 10
3 1 2
2 1 5
1 4 5
2 4 4
3 1 10
1 10 10
3 8 9
1 6 8
2 8 10
1 10 10
3 6 10
3 6 6
3 9 10
2 1 7
3 3 5
3 5 5
2 8 8
1 10 10
3 2 3
2 3 9
1 2 7
3 9 9
1 10 10
3 7 8
1 4 8
2 7 8
1 4 8
2 8 10
2 4 6

*/