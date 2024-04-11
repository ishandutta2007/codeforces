// CF 817E
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
const int m = 27;
struct node{
	int x;
	int lson;
	int rson;
}a[3333333];
int s;
void Add(int v,int p,int k,int d)
{
	if(k==0)
		return;
	a[k].x+=v;
	if(d<0)
		return;
	if((p>>d)&1){
		if(a[k].rson==0){
			s++;
			a[k].rson=s;
		}
		Add(v,p,a[k].rson,d-1);
	}
	else{
		if(a[k].lson==0){
			s++;
			a[k].lson=s;
		}
		Add(v,p,a[k].lson,d-1);
	}
}
int Query(int p,int l,int k,int d)
{
	if(k==0||d<0)
		return a[k].x;
	int b,c;
	b=(p>>d)&1;
	c=(l>>d)&1;
	if(c==0){
		if(b==0)
			return Query(p,l,a[k].lson,d-1);
		else
			return Query(p,l,a[k].rson,d-1);
	}
	else{
		if(b==0)
			return a[a[k].lson].x+Query(p,l,a[k].rson,d-1);
		else
			return a[a[k].rson].x+Query(p,l,a[k].lson,d-1);
	}
}
int main()
{
	int q,t,p,l,i,j;
	for(i=0;i<=3333330;i=i+1)
		a[i].x=0,a[i].lson=0,a[i].rson=0;
	s=1;
	cin>>q;
	for(i=1;i<=q;i=i+1)
	{
		scanf("%d%d",&t,&p);
		if(t==1)
			Add(1,p,1,m-1);
		if(t==2)
			Add(-1,p,1,m-1);
		if(t==3){
			scanf("%d",&l);
			printf("%d\n",Query(p,l-1,1,m-1));
			//for(j=1;j<=s;j=j+1)
			//	cout<<j<<' '<<a[j].x<<' '<<a[j].lson<<' '<<a[j].rson<<endl;
		}
	}
	return 0;
}
/*
5
1 3
1 4
3 6 6
2 4
3 6 3

*/