#include <iostream>
using namespace std;
long long n,m,d,bx,by,x,y,a[12],b[12],i,j;
main()
{
cin>>n>>bx;
for (i=1;i<=n;i++)
cin>>a[i];
d=1;
for (i=n;i>=1;i--)
{
x+=d*a[i];
d*=bx;
}
cin>>m>>by;
d=1;
for (i=1;i<=m;i++)
cin>>b[i];
for (i=m;i>=1;i--)
{
y+=d*b[i];
d*=by;
}
if (x>y)
cout<<">"<<endl;
else if (x<y)
cout<<"<"<<endl;
else
cout<<"="<<endl;
}