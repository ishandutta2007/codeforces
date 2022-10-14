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
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,y,v,a[4000],rez;
vector <ll> f;

int main()
{
    cin >> n >> v;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[x] += y;
    }
    x = v;
    for (i = 1; i < 3300; i++)
    {
        v = x;
        while (v&&a[i-1])
              v--,a[i-1]--,rez++;
        while (v&&a[i])
              v--,a[i]--,rez++;
    }
    cout << rez << endl;
    return 0;
}