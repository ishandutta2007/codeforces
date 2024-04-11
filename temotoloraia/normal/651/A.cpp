#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
main()
{
cin>>a>>b;
if (a>b)
swap(a,b);
while (true)
{
if (a*b==0)
break;
if (a>b)
swap(a,b);
if (b>=2)
{
b-=2;
a++;
}
else
break;
n++;
}
cout<<n<<endl;
}