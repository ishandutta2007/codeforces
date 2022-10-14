#include <iostream>
using namespace std;
int main(){
    int c,i,x1,x2,n,s,t;
    int a[500];
  
cin>>n;
for (i=1;i<n+1;i++)
cin>>a[i];
cin>>s>>t;
if (s==t) 
{
cout<<0;
return 0;
}
if (s>t)
{
c=s;
s=t;
t=c;
}
x1=0;x2=0;
for (i=1;i<n+1;i++)
if ((i>=s)&&(i<t))
x1=x1+a[i]; else x2=x2+a[i];
if (x1<x2) cout<<x1; else cout<<x2;
return 0;
}