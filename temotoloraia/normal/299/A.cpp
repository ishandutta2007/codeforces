#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, usg, a[100003], i;
main()
{
  cin>>n;
  for(i=0;i<n;i++)
cin>>a[i];
  sort(a,a+n);
  usg=a[0];
  for(i=1;i<n;i++)
{
if(a[i]%usg!=0)
{
usg=-1;
break;
}
}
  cout<<usg<<endl;
}