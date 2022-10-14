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
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,d,x,k,y,m,l,r,c,sum;
string s,s1;
int main()
{
    cin >> s;
    n = s.size();
    for (i = 0; i <= n; i++)
        for (char c = 'a'; c <= 'z'; c++)
    {
        s1.clear();
        for (j = 0; j < i; j++)
            s1.push_back(s[j]);
        s1.push_back(c);
        for (j = i; j < n; j++)
            s1.push_back(s[j]);
        ll z = 1;
        for (j = 0; j < s1.size()/2; j++)
            if (s1[j] != s1[s1.size() - j - 1])
               z = 0;
        if (z)
        {
           cout << s1 << endl;
           return 0;
        }
    }
    cout << "NA" << endl;
    return 0;
}