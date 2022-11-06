#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

map<string, int> goods;
map<string, int>::iterator it;

pair<int, int> get_good(string s1, string s2)
{
    int a(0), b(0);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if (s1[i] == s2[j])
            {
                if (i == j)
                    a++;
                else
                    b++;
            }
    return mp(a, b);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string s = "0000";
    int i, j, n, f, a, b;
    for(n = 0; n < 10000; n++)
    {
        for(i = 4 - 1; i >= 0; i--)
            if (s[i]=='9')
                s[i] = '0';
            else
            {
                s[i]++;
                break;
            }
        f = 0;
        for(i = 0; i < 4; i++)
            for(j = i + 1; j < 4; j++)
                if (s[i] == s[j])
                {
                    f = 1;
                }
        if (!f)
            goods[s] = 1;
    }
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s >> a >> b;
        for(it = goods.begin(); it != goods.end(); it++)
        {
            pair<int, int> tmp = get_good(it->first, s);
            if (tmp.first != a || tmp.second != b)
                it->second = 0;
        }
    }
    f = 0;
    for(it = goods.begin(); it != goods.end(); it++)
        if (it->second)
        {
            f++;
            s = it->first;
        }
    if (!f)
        cout << "Incorrect data";
    else if (f==1)
        cout << s;
    else cout << "Need more data";
}