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
ll n,l,r,i,j,k,x,y;
vector <ll> f;

int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        ll flag = 0;
        for (j = 0; j < x; j++)
        {
            cin >> y;
            if (y < k)
               flag = 1;
        }
        if (flag) f.push_back(i+1);
    }
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    cout << endl;
    return 0;
}