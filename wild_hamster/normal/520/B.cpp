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
#include <fstream>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll x,y,l,r,i,j,n,k,k1,k2,d,m,z[305];
string s;
int main()
{
    cin >> n >> m;
    ll rez = 0;
    while (m != n)
    {
        if (m > n)
        {
            if (m%2 == 1)
               m++;
            else
                m/=2;
        } else
        {
            m++;
        }
        rez++;
    }
    cout << rez << endl;
    return 0;
}