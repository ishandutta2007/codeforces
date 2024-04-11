//CF 487D
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
const int N = 111111;
const int M = 12;
const int inf = 1e9;
int n,m;
char c[N][M];
int t[N*5][M];
void solve(int k,int l){
	int i,x;
	//cout<<l<<endl;
	for(i=1;i<=m;i=i+1){
		x=i;
		if(c[l][i]=='>'){
			while(x<=m&&c[l][x]=='>'){
				x++;
			}
			if(x>m)
				t[k][i]=-l*M-m-1;
			else{
				if(c[l][x]=='<')
					t[k][i]=-inf;
				else
					t[k][i]=x;
			}
		}
		if(c[l][i]=='<'){
			while(x>=1&&c[l][x]=='<'){
				x--;
			}
			if(x<1)
				t[k][i]=-l*M-0;
			else{
				if(c[l][x]=='>')
					t[k][i]=-inf;
				else
					t[k][i]=x;
			}
		}
		if(c[l][i]=='^')
			t[k][i]=i;
		//cout<<t[k][i]<<' ';
	}
	//cout<<endl;
}
void unite(int k,int l,int r){
	int i,tmp;
	tmp=456789;
	for(i=1;i<=m;i=i+1){
		if(t[r][i]<0)
			t[tmp][i]=t[r][i];
		else
			t[tmp][i]=t[l][t[r][i]];
	}
	for(i=1;i<=m;i=i+1)
		t[k][i]=t[tmp][i];//,cout<<t[k][i]<<' ';
	//cout<<endl;
}
void build(int k,int l,int r){
	//cout<<l<<r<<endl;
	if(l==r){
		solve(k,l);
		return;
	}
	int md;
	md=(l+r)>>1;
	build(k<<1,l,md);
	build(k<<1|1,md+1,r);
	unite(k,k<<1,k<<1|1);
}
void modify(int k,int l,int r,int p,int pm,char v){
	if(l==r){
		c[p][pm]=v;
		solve(k,p);
		return;
	}
	int md;
	md=(l+r)>>1;
	if(p<=md)
		modify(k<<1,l,md,p,pm,v);
	else
		modify(k<<1|1,md+1,r,p,pm,v);
	unite(k,k<<1,k<<1|1);
}
void query(int k,int l,int r,int p){
	//cout<<l<<r<<p<<endl;
	if(r==p){
		unite(0,k,0);
		return;
	}
	int md;
	md=(l+r)>>1;
	if(md<p)
		query(k<<1|1,md+1,r,p);
	query(k<<1,l,md,min(md,p));
}
int main()
{
	char ch[M];
	int q,i,j,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%s",&ch);
		for(j=1;j<=m;j=j+1)
			c[i][j]=ch[j-1];
	}
	build(1,1,n);
	while(q--){
		scanf("%s%d%d",&ch,&x,&y);
		if(ch[0]=='A'){
			for(i=1;i<=m;i=i+1)
				t[0][i]=i;
			query(1,1,n,x);
			j=t[0][y];
			if(j==-inf)
				cout<<"-1 -1\n";
			else{
				if(j>0)
					cout<<"0 "<<j<<endl;
				else
					cout<<(-j)/M<<' '<<(-j)%M<<endl;
			}
		}
		else{
			scanf("%s",&ch);
			modify(1,1,n,x,y,ch[0]);
		}
	}
	return 0;
}