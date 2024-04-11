#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll n,i,j,k1,k2,x,k,y,m,l,r,c,t,sum,xors[100500];
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          else
          return gcd(b,a%b);
}
int main()
{
    cin >> n >> m >> x >> y;
    k1 = max(3*n/10,n-(n/250)*x);
    k2 = max(3*m/10,m-(m/250)*y);
    if (k1 > k2)
       cout << "Misha" << endl;
    else
    if (k1 < k2)
       cout << "Vasya" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}