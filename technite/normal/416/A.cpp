#include<bits/stdc++.h>
using namespace std;
int n,b;string a,c;
int main()
{
cin>>n;
int l=-2e9,r=2e9;
while(n--)
  {
  cin>>a>>b>>c;
  if (a==">"&&c=="Y"||a=="<="&&c=="N") l=max(l,b+1);
  else if (a==">="&&c=="Y"||a=="<"&&c=="N") l=max(l,b);
  else if (a=="<"&&c=="Y"||a==">="&&c=="N") r=min(r,b-1);
  else if (a=="<="&&c=="Y"||a==">"&&c=="N") r=min(r,b);
  }
if (l>r) puts("Impossible");
else cout<<l;
}