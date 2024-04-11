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
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll dp[100][30],i,j,n,k[5],k1,k2,m,y;
string s;
int main()
{
    cin >> n;
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
        s[i] -= '0';
    k[s[0]] = 1;
    for (i = 1; i < n; i++)
        if (k[s[i]^1] > 0)
        {
            k[s[i]^1]--;
        } else
        k[s[i]]++;
    cout << k[0]+k[1] << endl;
    return 0;
}