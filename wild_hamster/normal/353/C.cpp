#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <utility>
#include <complex>

using namespace std;

#define foreach(it,c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) c.begin(), c.end()
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define oo (1LL<<30)

typedef long long lint;
typedef pair <int, int> pii;

#define MAXN 100005

int n, array[MAXN], dp[MAXN][2];
string s;

int solve(int i, bool owe)
{
    if (dp[i][owe] != -1) return dp[i][owe];
    if (i == n) {
        if (owe) return -oo;
        else return 0;
    }
    
    return dp[i][owe] = max(
        solve(i+1, owe and (s[i]=='0')), 
        array[i] + solve(i+1, owe or (s[i]=='0'))
        );
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    cin >> s;
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0,0));
    
    return 0;
}