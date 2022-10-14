#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll rez,sum,k,m,k1,k2,k3,i,n,j;
char a[10][10];
vector <vector <ll> > f(100005);
int main()
{
for (i=0;i<8;i++)
for (j=0;j<8;j++)
cin>>a[i][j];
for (i=0;i<8;i++)
for (j=0;j<7;j++)
if (a[i][j]==a[i][j+1]) {cout<<"NO";return 0;}
cout<<"YES";
return 0;
}