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
#define MOD (((ll)1e+17)+7)
#define x1 ldfjgldf
#define x2 lfhlgfjhklgh
#define y1 klfjdhgkldfjhkldf
#define y2 ldfjgkldfjgkldfjhl
#define MX 1000000
typedef long long ll;
using namespace std;
ll l,r,i,j,n,k,m,x,y,x1,y1,cons,a[100500],p3[700500];
map <ll,ll> map_hash[700500];
string s,s1;


int main()
{
    
    cin >> n >> m;
    p3[0] = 1;
    for (i = 1; i < 600300; i++)
        p3[i] = (p3[i-1]*3)%MOD;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        ll hsh = 0;
        for (j = 0; j < s.size(); j++)
            hsh = (hsh*3+s[j] - 'a')%MOD;
        ll x = s.size();
        for (j = 0; j < s.size(); j++)
        {
            for (char c = 'a'; c <= 'c'; c++)
            if (c != s[j])
            {
                ll hsh1 = (ll)(c-s[j])*p3[x-j-1];
                hsh1 = (hsh + hsh1 + 3LL*MOD)%MOD;
                map_hash[x][hsh1] = 1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        cin >> s;
        ll hsh = 0;
        for (j = 0; j < s.size(); j++)
            hsh = (hsh*3+s[j] - 'a')%MOD;
        ll x = s.size();
        if (map_hash[x][hsh] == 1)
           cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}