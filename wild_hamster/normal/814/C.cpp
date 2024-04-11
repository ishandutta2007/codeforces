#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#include <unordered_map>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 1000000
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,h,H,sz,cur,sum,q;
ll n;
int a[10500][35], used[500005], b[100500], dp[100500][35];
vector<ll> f,g;
string s;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            a[i+1][j] = a[i][j];
        a[i+1][s[i]-'a']++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            dp[i][j] = 0;
    for (int c = 0; c < 26; c++)
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                dp[j-i+1-(a[j+1][c]-a[i][c])][c] = max(dp[j-i+1-(a[j+1][c]-a[i][c])][c], j-i+1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> x >> c;
        cout << dp[x][c-'a'] << endl;
    }
    return 0;
}