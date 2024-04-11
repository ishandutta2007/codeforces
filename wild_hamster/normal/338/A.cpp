#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000009
ll rez,x1,ost,x,n,k,m,t,r,y,i;
ll binpow(ll x, ll k)
{
if (k==0) return 1; 
if (k%2==1) return (binpow(x,k-1)*x)%tr; 
ll t=binpow(x,k/2);
return (t*t)%tr;
}
int main()
{
cin>>n>>m>>k;
//if ((n+1)/k>=m/(k-1)) {cout<<m<<endl;return 0;}
x=n/(k+1);
ost=max((ll)0,n-x*(k+1)-1);
rez=n/k-n+m;
if (rez<0) rez=0;
//cout<<rez<<endl;
y=((binpow(2,rez+1)-2)*k)%tr;
y+=m-rez*k;
cout<<(y+tr)%tr<<endl;
return 0;
}