#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
using namespace std;
int n,m,h,t;
vector<int>a[100010];
int v[100010];
bool check(int x,int y,int dx,int dy,int get)
{
int nx=dx-get-t;
int ny=dy-get-h;
if(-nx-ny<=get&&dx>=t&&dy>=h)
{
puts("YES");
printf("%d %d\n",y,x);
int p=0;
fe(it,a[y])
if(!v[*it]&&*it!=x)
{
++p;
printf("%d ",*it);
if(p==h) break;
}
if(p<h)
fe(it,a[y])
if(v[*it]&&*it!=x)
{
++p;
printf("%d ",*it);
v[*it]=0;
if(p==h) break;
}
puts("");
p=0;
fe(it,a[x])
if(v[*it]&&*it!=y)
{
++p;
printf("%d ",*it);
if(p==t) break;
}
puts("");
return true;
}
nx=dx-get-h;
ny=dy-get-t;
if(-nx-ny<=get&&dx>=h&&dy>=t)
{
puts("YES");
printf("%d %d\n",x,y);
vector<int> g;
int p=0;
fe(it,a[y])
if(!v[*it]&&*it!=x)
{
++p;
g.push_back(*it);
if(p==t) break;
}
if(p<t)
fe(it,a[y])
if(v[*it]&&*it!=x)
{
++p;
g.push_back(*it);
v[*it]=0;
if(p==t) break;
}
p=0;
fe(it,a[x])
if(v[*it]&&*it!=y)
{
++p;
printf("%d ",*it);
if(p==h) break;
}
puts("");
for(int i=0;i<t;i++)
printf("%d ",g[i]);
puts("");
return true;
}
return false;
}
int main()
{
cin>>n>>m>>h>>t;
for(int i=1;i<=m;i++)
{
int x,y;
scanf("%d%d",&x,&y);
a[x].push_back(y);
a[y].push_back(x);
}
for(int i=1;i<=n;i++)
{
int dx=a[i].size()-1;
for(int k=0;k<a[i].size();++k)
v[a[i][k]]=1;
for(vector<int>::iterator it=a[i].begin();it!=a[i].end();++it)
{
int dy=a[*it].size()-1;
if(dx>=h+t&&dy>=h+t)
{
puts("YES");
memset(v,0,sizeof(v));
printf("%d %d\n",i,*it);
int get=0;
for(int k=0;k<a[i].size();++k)
if(a[i][k]!=*it)
{
++get;
printf("%d ",a[i][k]);
v[a[i][k]]=1;
if(get==h) break;
}
puts("");
get=0;
for(int k=0;k<a[*it].size();++k)
if(a[*it][k]!=i&&!v[a[*it][k]])
{
++get;
printf("%d ",a[*it][k]);
if(get==t) break;
}
puts("");
return 0;
}
if(dy<h+t)
{
int get=0;
for(int k=0;k<a[*it].size();++k)
if(a[*it][k]!=i)
if(v[a[*it][k]]) ++get;
if(check(i,*it,dx,dy,get)) return 0;
}
}
for(int k=0;k<a[i].size();++k)
v[a[i][k]]=0;
}
puts("NO");
return 0;
}