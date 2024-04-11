#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
ll a[300001],b[300000],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
struct A
{
ll a,b;
};
bool f(A x, A y)
{
if (x.a<y.a) return true;
else if (x.a==y.a&&x.b<y.b) return true; else return false;
}
int main()
{
    A t[15];
for (i=0;i<8;i++)
cin>>t[i].a>>t[i].b;
sort(t,t+8,f);
//for (i=0;i<8;i++)
//cout<<t[i].a<<" "<<t[i].b<<endl;
if (t[0].a==t[1].a&&t[2].a==t[1].a&&t[3].a==t[4].a&&t[5].a==t[6].a&&t[6].a==t[7].a&&
t[0].b==t[3].b&&t[3].b==t[5].b&&t[1].b==t[6].b&&t[2].b==t[4].b&&t[4].b==t[7].b
&&t[0].a!=t[3].a&&t[3].a!=t[5].a&&t[0].b!=t[1].b&&t[1].b!=t[2].b)
cout<<"respectable"<<endl; else cout<<"ugly"<<endl;
return 0;
}