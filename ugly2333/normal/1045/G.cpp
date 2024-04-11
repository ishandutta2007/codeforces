//CF1045G
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
const int N = 333333;
int n,k,m,s,a[N],l[N],r[N],b[N],p[N],e[N];
map<int,int> M,S;
map<int,int>::iterator it;
vector<int> v[N],c[N],q[N],g,f[N];
LL ans;
int t[N];
void ad(int x,int y){
	while(x<=m){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
void an(int x,int y){
	ans+=qu(y);
	ans-=qu(x-1);
}
void cal(vector<int>&v){
	int i,j;
	for(i=v.size();i--;)
		t[v[i]]++;
	for(i=v.size();i--;){
		for(j=v[i]+1;j<=s;j=j+1){
			if(e[j]-e[v[i]]>k)
				break;
			ans-=t[j];
		}
	}
	for(i=v.size();i--;){
		ans-=(LL)t[v[i]]*(t[v[i]]+1)/2;
		t[v[i]]=0;
	}
}
int main()
{
	int i,j,o,x,y;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",a+i,&x,b+i);
		l[i]=a[i]-x;
		r[i]=a[i]+x;
		M[a[i]]=1,M[l[i]]=1,M[r[i]+1]=1;
		S[b[i]]=1;
	}
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m,p[m]=(*it).first;
	for(it=S.begin();it!=S.end();it++)
		(*it).second=++s,e[s]=(*it).first;
	for(i=1;i<=n;i=i+1){
		a[i]=M[a[i]],l[i]=M[l[i]],r[i]=M[r[i]+1]-1;
		b[i]=S[b[i]];
		v[b[i]].push_back(i);
		f[a[i]].push_back(b[i]);
	}
	for(i=1;i<=m;i=i+1)
		cal(f[i]);
	for(i=1;i<=s;i=i+1){
		g.clear();
		for(j=e[i]-k;j<=e[i]+k;j=j+1){
			if(S.find(j)==S.end())
				continue;
			o=S[j];
			for(x=v[o].size();x--;){
				y=v[o][x];
				g.push_back(r[y]);
				c[r[y]].push_back(a[y]);
			}
		}
		for(x=v[i].size();x--;){
			y=v[i][x];
			g.push_back(a[y]);
			q[a[y]].push_back(l[y]);
		}
		sort(g.begin(),g.end());
		g.resize(unique(g.begin(),g.end())-g.begin());
		for(j=g.size();j--;){
			o=g[j];
			for(x=c[o].size();x--;)
				ad(c[o][x],1);
			for(x=q[o].size();x--;)
				an(q[o][x],o);
		}
		for(j=g.size();j--;){
			o=g[j];
			for(x=c[o].size();x--;)
				ad(c[o][x],-1);
			c[o].clear();
			q[o].clear();
		}
	}
	cout<<ans;
	return 0;
}