#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef double DB;
const int N = 3333;
int n,m,a[N],b[N],c[N],d[N],f[N];
vector<int> v[N],h;
DB ans,w[N];

int fnd(int x){
if(f[x]==x) return x;
return f[x]=fnd(f[x]);
}

void dfs0(int u,int o){
if(b[u]) return;
if(!b[o]) h.push_back(u);
b[u]=1;
for(int i=v[u].size();i--;)dfs0(v[u][i],o);
if(!b[o]) h.pop_back();
}

void dfs1(int u,int fa){
if(b[u]) return;
b[u]=1;
if(!c[u]) c[u]=c[fa];
for(int i=v[u].size();i--;)dfs1(v[u][i],u);
}

void dfs2(int u,int fa){
if(b[u])return;
b[u]=1;
d[u]=d[fa]+1;
for(int i=v[u].size();i--;)dfs2(v[u][i],u);
}

int main(){
int i,j,x,y,z;
scanf("%d",&n);
for(i=1;i<=n;i=i+1)f[i]=i,w[i]=(DB)1.0/(DB)i;
for(i=1;i<=n;i=i+1){
scanf("%d%d",&x,&y);
x++,y++;
if(fnd(x)!=fnd(y)) v[x].push_back(y),v[y].push_back(x),f[fnd(x)]=fnd(y);
else a[0]=x,a[1]=y;
}
memset(b,0,sizeof(b));
dfs0(a[1],a[0]);

m=h.size();
for(i=2;i<=m;i=i+1)a[i]=h[i-1];
for(i=1;i<=m;i=i+1)c[a[i]]=i;
memset(b,0,sizeof(b));
dfs1(a[1],0);

for(i=1;i<=n;i=i+1){
memset(b,0,sizeof(b));
dfs2(i,0);
for(j=1;j<=n;j=j+1){
if(c[i]==c[j]&&i<j) ans+=w[d[j]];
if(c[i]>=c[j]) continue;
x=d[j],z=x+c[i]-1+m-c[j],y=z-(c[j]-c[i]-1);
ans+=w[x]+w[y]-w[z];
}

}
ans+=ans+n;
printf("%.9lf",ans);
return 0;
}