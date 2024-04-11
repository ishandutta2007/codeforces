#include <iostream>
using namespace std;
int main()
{
int i,t,s,k,m,n;
cin>>n>>m;
if (((n==5)&&(m==3))||((n==6)&&(m==3)))
{
cout<<-1;
return 0;
}
k=n-m;s=0;
for (i=0;i<m;i++)
{
cout<<i*m<<" "<<s<<endl;
s=s+m-i;
}
t=m*m-m;
s=s+m*m+1;
for (i=0;i<k;i++)
{
s=s+i+1;
cout<<t-i*m<<" "<<s<<endl;
}
return 0;
}