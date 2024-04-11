//CF 1152E
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
const int N = 222222;
int n,m,w,a[N],b[N],c[N],f[N],p[N],l[N],r[N],d[N];
map<int,int> M;
map<int,int>::iterator it;
multiset<int> S[N];
int sz,e[N];
vector<int> v[N],t[N];
queue<int> q;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void era(multiset<int>&s,int x){
	s.erase(s.lower_bound(x));
}
void del(int x,int y){
	era(S[x],y);
	era(S[y],x);
}
void dfs(int u){
	if(!S[u].size())
		return;
	e[++sz]=u;
	f[u]=1;
	int x=*(S[u].begin());
	del(u,x);
	if(f[x]){
		w++;
		while(e[sz]!=x){
			t[w].push_back(e[sz]);
			v[e[sz]].push_back(w);
			f[e[sz--]]=0;
		}
		t[w].push_back(x);
		v[x].push_back(w);
		f[e[sz--]]=0;
	}
	dfs(x);
}
void adq(int u){
	if(p[u])
		return;
	int i,x;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(!f[x])
			q.push(x);
		f[x]=1;
	}
}
int main()
{
	int i,j,x,y,z,xx,yy;
	scanf("%d",&m);
	for(i=1;i<m;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<m;i=i+1){
		scanf("%d",b+i);
		if(a[i]>b[i]){
			cout<<-1;
			return 0;
		}
		M[a[i]]=1;
		M[b[i]]=1;
	}
	n=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++n,c[n]=(*it).first;
	for(i=1;i<=n;i=i+1)
		f[i]=i;
	for(i=1;i<m;i=i+1){
		a[i]=M[a[i]];
		b[i]=M[b[i]];
		S[a[i]].insert(b[i]);
		S[b[i]].insert(a[i]);
		f[fnd(a[i])]=fnd(b[i]);
		//cout<<a[i]<<b[i]<<endl;
	}
	for(i=1;i<=n;i=i+1){
		if(fnd(i)!=fnd(1)){
			cout<<-1;
			return 0;
		}
	}
	x=0,y=0;
	for(i=1;i<=n;i=i+1){
		if(S[i].size()&1){
			if(!x)
				x=i;
			else{
				if(!y)
					y=i;
				else{
					cout<<-1;
					return 0;
				}
			}
		}
	}
	if(!x)
		x=1,y=1;
	S[x].insert(y);
	S[y].insert(x);
	xx=x,yy=y;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i=i+1)
		dfs(i);
	adq(1);
	sz=1;
	p[1]=1,l[1]=1,r[1]=1,d[1]=1;
	while(!q.empty()){
		i=q.front();
		q.pop();
		for(j=0;j<t[i].size();j=j+1)
			adq(t[i][j]);
		for(j=0;j<t[i].size();j=j+1)
			if(p[t[i][j]])
				break;
		z=j;
		x=p[t[i][j]],y=++sz;
		r[y]=r[x],d[y]=d[x];
		for(j=z+1;j<t[i].size();j=j+1)
			sz++,r[x]=sz,l[sz]=x,d[sz]=t[i][j],p[t[i][j]]=sz,x=sz;
		for(j=0;j<z;j=j+1)
			sz++,r[x]=sz,l[sz]=x,d[sz]=t[i][j],p[t[i][j]]=sz,x=sz;
		r[x]=y,l[y]=x;
	}
	sz=0;
	x=1;
	for(i=1;i<=m+1;i=i+1)
		e[++sz]=d[x],x=r[x];
	x=xx,y=yy;
	for(i=1;i<=m;i=i+1)
		if((e[i]==x&&e[i+1]==y)||(e[i]==y&&e[i+1]==x))
			break;
	z=i;
	for(i=z+1;i<=m;i=i+1)
		cout<<c[e[i]]<<' ';
	for(i=1;i<=z;i=i+1)
		cout<<c[e[i]]<<' ';
	return 0;
}