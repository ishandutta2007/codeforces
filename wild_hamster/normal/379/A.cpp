#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 5000
#define NN 25000000
vector <ll> lal;
ll s,i,j,m,n,k,x,y,x1,x2,y1,y2,rez,a,b,k1,k2;
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}
int main()
{
ll rez = 0;
cin >> a >> b;
k1 = a; k2 = 0;
rez = 0;
while (k1)
{
    //  cout << k1 << endl;
 k1--;
 rez++;
 k2++;
 if (k2 == b) 
 {
        k2 -= b;
        //rez++;
        k1++;
 }
}
if (k2 == b) rez++;
cout << rez << endl;
return 0;
}