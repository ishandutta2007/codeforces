#include <bits/stdc++.h>
using namespace std;
string s,ss;
int m,l,r,k,i,j,n,p;
int main()
{
cin>>s;
cin>>m;
ss=s;
for (i=1;i<=m;i++)
{
cin>>l>>r>>k;
r--;
l--;
for (j=l;j<=r;j++)
{
p=r-l+1;
ss[j]=s[l+((j-l-k)%p+p)%p];
}
s=ss;
}
cout<<ss<<endl;
}