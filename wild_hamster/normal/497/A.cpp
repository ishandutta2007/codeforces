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
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
ll x,y,n,m,q,i,j,k,rez;
string s[1050],t;
vector <pair<ll,ll> > f[1050];
char c;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
    {
        cin >> c;
        s[j].push_back(c);
    }
    rez = 0;
    f[0].push_back(mp(0,n-1));
    for (i = 0; i < m; i++)
    {        
    ll flag = 1;
        for (j = 0; j < f[i].size(); j++)
        {
            k = f[i][j].first;
            ll left = k, right = k;
            while (k < f[i][j].second)
            {
                 // cout << s[i][k+1] << " " << s[i][k] << endl;
                if (s[i][k+1] < s[i][k])
                   flag = 0;
                else
                if (s[i][k+1] == s[i][k])
                   right++;
                else
                {
                    if (right > left)
                    f[i+1].push_back(mp(left,right));
                    right = left = k+1;
                }
                k++;
                
            }
            if (right > left)
                f[i+1].push_back(mp(left,right));
        }
        if (flag == 0)
        {
                 rez++;
                 f[i+1].clear();
                 for (j = 0; j < f[i].size(); j++)
                     f[i+1].push_back(f[i][j]);
        }
        
    }
    cout << rez << endl;
    return 0;
}