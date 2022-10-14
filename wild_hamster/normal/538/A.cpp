#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef long long ll;
ll i,n,j,k,x,y,z,m,l,r,a[228228];
string s;

int main()
{
    cin >> s;
    if (s.size() < 10)
    {
     cout << "NO" << endl;
     return 0;
    }
    n = s.size();
    ll flag = 0;
    for (i = 0; i <= 10; i++)
    {
        string s1 = "";
        s1.append(s.substr(0,i));
        s1.append(s.substr(n-(10-i),10-i));
        if (s1 == "CODEFORCES")
           flag = 1;
    }
    if (flag)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}