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
ll n,l,r,i,j,k,x,m,y,v,a[204000],pos[1005000],used[1005000],rez;
vector <ll> f;

int main()
{
    cin >> m >> n;
    ll flag = 0;
    for (i = 0; i < 100500; i++)
        if (m%n == 0)
        {
                flag = 1;
                break;
        } else
        m += m%n;
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}