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
ll i,j,n,l,r,rez,k,m,y,z,q,x,a[100500],next;
vector <ll> f;
string s;
int main()
{
    cin >> n;
    f.pb(1); f.pb(2); f.pb(3); f.pb(4); f.pb(6); f.pb(12);
    for (i = 0; i < n; i++)
    {
        vector <ll> g;
        cin >> s;
        for (j = 0; j < f.size(); j++)
        {
        ll flag2 = 0;
            for (k = 0; k < f[j]; k++)
            {
                ll flag = 1;
                for (x = k; x < 12; x+=f[j])
                    if (s[x] == 'O')
                       flag = 0;
                if (flag) flag2 = 1;
            }
        if (flag2) g.pb(f[j]);
        }
        cout << g.size() << " ";
        reverse(g.begin(),g.end());
        for (j = 0; j < g.size(); j++)
            cout << 12/g[j] << "x" << g[j] << " ";
        cout << endl; 
    }
    return 0;
}