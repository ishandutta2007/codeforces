#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 95542721
//map <ll,ll> a,b,c;
ll cube(ll s)
{
s=(((s*s)%tr)*s)%tr;
return s;
}
ll k1,k2,k3,k4;
db q,rez;
int main() 
{
cin>>k1>>k2>>k3>>k4;
q=(1-(db)k1/k2)*(1-(db)k3/k4);
rez=(db)k1/k2*(1./(1-q));
printf("%.10f",rez);
return 0;
}