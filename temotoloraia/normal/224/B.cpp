#include<bits/stdc++.h>
using namespace std;
set<long long>a1, a2;
long long l, ans, n, i, p,a[100005], r, k;
string s;
char x;
main(){
  cin>>n>>k;
  if(n==1 && k==1)
cout<<"1 1"; 
else
{
  for(i=0;i<n;i++)
cin>>a[i];
  i=0;
  while(a1.size()!=k && i<n)
{
a1.insert(a[i]);
r++;
i++;
}
 i=r-1;
 l=r;
  while(a2.size()!=k && i>=0)
{
a2.insert(a[i]);
i--;
l--;
}
if (l+1<=0 || r<1 || a2.size()!=k)
cout<<"-1 -1"<<endl;
else
  cout<<l+1<<" "<<r;
}
}