#include<iostream>
#include<set>
using namespace std;
int n,m,i,j;
set<int> s[105];
long long k=1;
char c;
int main()
{
cin>>n>>m;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
cin>>c,s[j].insert(c);
for(i=1;i<=m;i++)
k=(k*s[i].size())%1000000007;
cout<<k;
return 0;
}