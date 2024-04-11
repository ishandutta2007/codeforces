#include <bits/stdc++.h>
using namespace std;
int m,n,k,a,b,c,x,y,z,i;
main()
{
cin>>m>>n>>k;
/*x=__gcd(k,n);
y=__gcd(m,k);
z=__gcd(m,n);*/
for (b=1;b<=min(m,k);b++)
{
c=m/b;
a=n/c;
if (a*c==n && a*b==k && b*c==m)
{
cout<<4*(a+b+c)<<endl;
break;
}
}
}