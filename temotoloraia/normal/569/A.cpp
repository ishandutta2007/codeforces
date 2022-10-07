#include <iostream>
using namespace std;
double t,s,q,i,x,x0,t1;
int k=0;
int main()
{
cin>>t>>s>>q;
x0=s;
x=x0;
while (x0<t-0.0001)
{
k++;
t1=x0*q;
x0=t1;
}
cout<<k<<endl;
}