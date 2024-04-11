//CF 627E
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
const int N = 3333;
int n,m,w,k,a[N],b[N],e,c[N],l[N],r[N],p[N];
vector<int> v[N];
set<int> S;
LL s,ans;
void ins(int x){
	int u=c[x];
	p[++e]=x;
	c[x]=e;
	if(!u){
		u=c[*S.lower_bound(x)];
		S.insert(x);
	}
	r[e]=u,l[e]=l[u];
	r[l[e]]=e,l[r[e]]=e;
}
void ad(int x){
	int i,o;
	ins(x);
	o=e;
	for(i=k;i>=0;i=i-1){
		a[i]=p[o];
		o=l[o];
	}
	o=e;
	for(i=0;i<=k;i=i+1){
		b[i]=p[o];
		o=r[o];
	}
	for(i=1;i<=k;i=i+1)
		s+=(a[i]-a[i-1])*(b[i]-b[i-1]);
}
int main()
{
	int i,j,o,h;
	scanf("%d%d%d%d",&n,&m,&w,&k);
	for(o=1;o<=w;o=o+1){
		scanf("%d%d",&i,&j);
		v[i].push_back(j);
	}
	for(i=1;i<=n;i=i+1){
		S.clear();
		memset(c,0,sizeof(c));
		e=2;
		S.insert(0),S.insert(m+1);
		c[0]=1,c[m+1]=2,p[1]=0,p[2]=m+1;
		l[1]=1,r[1]=2,l[2]=1,r[2]=2;
		s=0;
		for(j=i;j<=n;j=j+1){
			for(o=0;o<v[j].size();o=o+1)
				ad(v[j][o]);
			ans+=s;
		}
	}
	cout<<ans;
	return 0;
}