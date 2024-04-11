//CF156E
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
const int N = 66666;
const int M = 25;
const int D = 15;
int p[M]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int g[M],e[M][111],r[M][111];
struct node{
	int a[M],b[M];
	node(){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
}f[D][N],t[N],ans;
void operator+=(node&p,node&q){
	for(int i=0;i<M;i++)
		p.a[i]+=q.a[i],p.b[i]+=q.b[i];
}
void operator-=(node&p,node&q){
	for(int i=0;i<M;i++)
		p.a[i]-=q.a[i],p.b[i]-=q.b[i];
}
int go(int x,int y,int z){
	x+=2;
	int o=1;
	while(z--){
		o*=x;
	}
	return y-o*((y/o)%x);
}
int n,d,dd,l,h[N],w[N],c[N];
string s,ss;
void dfs1(int u,int k){
	if(u==l){
		ans+=t[k];
		return;
	}
	k*=dd;
	if(c[u]>=0){
		dfs1(u+1,k+c[u]);
		return;
	}
	for(int i=0;i<dd;i=i+1)
		dfs1(u+1,k+i);
}
int fl;
void dfs2(int u,int k){
	if(u==l){
		//cout<<k<<fl<<endl;
		if(fl)
			ans-=f[d][k];
		else
			ans+=f[d][k];
		return;
	}
	k*=dd;
	if(c[u]<0){
		dfs2(u+1,k);
		return;
	}
	if(c[u]>0){
		dfs2(u+1,k+c[u]);
		return;
	}
	dfs2(u+1,k);
	fl^=1;
	for(int i=1;i<dd;i=i+1)
		dfs2(u+1,k+i);
	fl^=1;
}
int main()
{
	int i,j,k,x,y;
	LL z,zz;
	for(i=0;i<M;i=i+1){
		for(j=1;j<p[i];j=j+1){
			for(k=1,x=j;x!=1;k=k+1,x=x*j%p[i]);
			if(k==p[i]-1){
				g[i]=j;
				break;
			}
		}
		e[i][0]=1;
		for(j=1;j<p[i]-1;j=j+1)
			e[i][j]=e[i][j-1]*g[i]%p[i];
		for(j=0;j<p[i]-1;j=j+1)
			r[i][e[i][j]]=j;
	}
	cin>>n;
	for(i=0;i<n;i=i+1){
		cin>>z;
		t[i]=node();
		for(j=0;j<M;j=j+1){
			if(z%p[j])
				t[i].a[j]=r[j][z%p[j]];
			else{
				zz=z;
				while(zz%p[j]==0){
					t[i].b[j]++;
					zz/=p[j];
				}
			}
		}
		for(j=0;j<D;j=j+1)
			f[j][i]=t[i];
	}
	for(i=0;i<D;i=i+1){
		for(k=0,x=1;x<n;k=k+1,x=x*(i+2));
		h[i]=k,w[i]=x;
		for(j=0;j<h[i];j=j+1){
			for(k=0;k<w[i];k=k+1){
				x=go(i,k,j);
				if(x!=k)
					f[i][x]+=f[i][k];
			}
		}
	}
	cin>>n;
	while(n--){
		cin>>d>>s>>z;
		dd=d,d-=2;
		while(s.length()<h[d]){
			s='0'+s;
		}
		l=s.length();
		x=0;
		for(j=0;j+h[d]<l;j=j+1)
			if(s[j]!='0'&&s[j]!='?')
				x=1;
		if(x){
			x=N;
			for(j=0;j<M;j=j+1)
				if((z+1)%p[j]==0)
					x=min(x,p[j]);
			if(x>=N)
				x=-1;
			cout<<x<<endl;
			continue;
		}
		for(ss="";j<l;j=j+1)
			ss+=s[j];
		s=ss;
		l=h[d];
		for(j=0;j<l;j=j+1){
			if(s[j]=='?'){
				c[j]=-1;
				continue;
			}
			if(s[j]>='A')
				c[j]=s[j]-'A'+10;
			else
				c[j]=s[j]-'0';
		}
		x=0,y=0;
		for(j=0;j<l;j=j+1){
			if(s[j]=='?')
				x++;
			if(s[j]=='0')
				y++;
		}
		ans=node();
		if(x<=y)
			dfs1(0,0);
		else
			dfs2(0,0);
		x=N;
		for(j=0;j<M;j=j+1){
			ans.a[j]%=p[j]-1;
			if(ans.b[j])
				y=0;
			else
				y=e[j][ans.a[j]];
			if((z+y)%p[j]==0)
				x=min(x,p[j]);
		}
		if(x>=N)
			x=-1;
		cout<<x<<endl;
	}
	return 0;
}