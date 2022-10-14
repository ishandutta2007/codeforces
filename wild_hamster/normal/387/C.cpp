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
ll n,i,j,d,m,x,y,p,k,max1,a[105000],b[5000],e,l,rez,rows,cols;
string s1,s2,s;
vector <pair<ll,ll> > f;
int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        l = s[i] - '0';        
        i++;
        ll tmp = 1;
        while (s[i] == '0'&& i < s.size()) i++,tmp++;
        f.push_back(mp(l,tmp));
        i--;
    }
    ll fist = f[0].first;
    ll length = f[0].second;
    j = 0;
    for (i = 1; i < f.size(); i++)
    {
        //cout << fist << " " << f[i].first << endl;
        if (length < f[i].second || (length == f[i].second&&fist < f[i].first))
           j = i;
        length += f[i].second;
    }
    cout << f.size() - j << endl;
    return 0;
}