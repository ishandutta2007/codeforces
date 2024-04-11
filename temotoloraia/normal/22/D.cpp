#include<bits/stdc++.h>
using namespace std;
int n,i,pos[10001],neg[10001];
vector<int>v;
struct seg{int a,b;};
seg m[1001];
bool operator<(seg x, seg y)
{
return x.b<y.b;
}
bool check()
{
int i1,i2;
for (i1=m[i].a;i1<=m[i].b;i1++)
if ((i1>=0 && pos[i1]>0) || (i1<0 && neg[abs(i1)]>0))
return false;
return true;
}
main()
{
cin>>n;
for (i=0;i<n;i++)
{
cin>>m[i].a>>m[i].b;
if (m[i].a>m[i].b)
swap(m[i].a,m[i].b);
}
sort(m,m+n);
for (i=0;i<n;i++)
{
if (check())
{
v.push_back(m[i].b);
if (m[i].b<0)
neg[abs(m[i].b)]=1;
else
pos[m[i].b]=1;
}
}
cout<<v.size()<<endl;
for (i=0;i<v.size();i++)
cout<<v[i]<<" ";
}