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
ll x,y,l,r,i,j,n,k,k1,k2,d,z[305];
string s;
int main()
{
    cin >> y;
    cin >> s;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
           z[s[i]-'a'] = 1;
        else
            z[s[i] - 'A'] = 1;
    for (i = 0; i < 26; i++)
        x += z[i];
    if (x == 26)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}