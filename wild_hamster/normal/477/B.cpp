#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,b;
ll gcd(ll a, ll b)
{
 if (a%b == 0) return b;
 return gcd(b,a%b);
}
set <ll> numbers;
set <ll>::iterator itr;
vector <ll> f;
vector <vector <ll> > kokoko;
int main()
{
    ll max1 = 0;
 cin >> n >> k;
    cout << (n*6-1)*k << endl;
    for (i = 0; i < n; i++)
        cout << (6*i+1)*k << " " << (6*i+2)*k << " " << (6*i+3)*k << " " << (6*i+5)*k << endl;
   return 0;
}