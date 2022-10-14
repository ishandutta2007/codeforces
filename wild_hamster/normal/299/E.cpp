#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
int main()
{
    //freopen("1.txt","w",stdout);
    vector <ll> f;
ll rez,k1,k2,k3,k4,i,j,r,n,k,a,b,c,x,y,z;
cin>>n;
rez=0;
if (n%3!=0) {cout<<0;return 0;}
k=(ll)n/3;
for (i=2;i<=sqrt((db)k);i++)
if (k%i==0) f.push_back(i);
if (f.size())
for (i=f.size()-1;i>=0;i--) 
if (f[i]*f[i]!=k) f.push_back(k/f[i]);
for (i=0;i<f.size();i++)
if (f[i]*f[i]*f[i]<=k)
{
x=f[i];
k1=k/x;
k3=sqrt((db)k1);
for (j=i;j<f.size();j++)
if (f[j]*f[j]<=k1&&k1%f[j]==0)
{
y=f[j];
z=k1/y;
ll a=(x-z+y)/2;if (2*a!=x-z+y||a<=0) continue;
ll b=(x+z-y)/2;if (2*b!=x+z-y||b<=0) continue;
ll c=(-x+z+y)/2;if (2*c!=-x+z+y||c<=0) continue;
if (a==b&&b==c) rez++; else
if (a!=b&&a!=c&&b!=c) rez+=6; else rez+=3;
//cout<<a<<" "<<b<<" "<<c<<endl;
//if (a1-(int)a1==0&&b1-(int)b1==0&&c1-(int)c1==0) rez++;
}
}
cout<<rez<<endl;
return 0;
}