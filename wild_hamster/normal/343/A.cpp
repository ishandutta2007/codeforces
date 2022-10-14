#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
map <string,int> f;
string g;
ll j,x,n,k,a[100500],d,l,r,i;
void gcd(ll a, ll b)
{
if (b==0) {return;}
else {x+=a/b;gcd(b,a%b);}
}
int main()
{
cin>>n>>k;
x=0;
gcd(n,k);
cout<<x<<endl;
return 0;
}