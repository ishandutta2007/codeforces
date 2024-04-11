#include <omp.h>
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
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, qt, qh, md,  x, y, p, a[1005][1005], c[30];
string s,t;
vector <ll> ans;
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> s >> t;
    n = s.size();
    k = 0;
    for (i = 0; i < n; i++)
        if (s[i] != t[i])
           k++;
    if (k%2)
    {
        cout << "impossible" << endl;
        return 0;
    }
    l = k/2; r = k/2;
    for (i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (l==0)
               cout << t[i];
            else
            {
                cout << s[i];
                l--;
            }
        } else
        cout << s[i];
    }
    return 0;
}