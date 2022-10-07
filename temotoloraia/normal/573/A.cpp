#include <iostream>
using namespace std;
int n,ans;
 int evklide (int g)
 {
     if (g%3==0)
     return evklide (g/3);
     if (g%2==0)
     return evklide (g/2);
     return g;
 }
main ()
{
      cin>>n;
      int a[n];
      for (int i=0;i<n;i++)
      cin>>a[i];
      for (int i=0;i<n;i++)
      a[i]=evklide (a[i]);
      for (int i=0;i<n;i++)
      {
      for (int j=0;j<n;j++)
      {
          if (a[i]!=a[j])
          ans=1;
          break;
}
if (ans==1)
break;
}
if (ans==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;         
}