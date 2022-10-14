#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
ll a,b,c,s,j,min1,i,m,n,k,k1,o;
cin>>a>>b>>c;
cout<<4*(sqrt((a*b)/c)+sqrt((a*c)/b)+sqrt((c*b)/a));
return 0;
}