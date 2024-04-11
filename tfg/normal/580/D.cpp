#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>

using ll = long long;

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;

ll dp[1<<18][18]{};

ll rule[18][18]{};

ll n, m, k; //n - dishes, m - eaten, k - rules

ll solve(vector<ll> &a, int mask, int node, int cur)
{
    if (dp[mask][node] != -1) return dp[mask][node];
    
    if (cur == m) return 0; //already bought m
    
    ll ret = 0;
    
    for (int i = 0; i < n; i++) //add not in set
    {
        if (!(mask & (1 << i))) //i not in set
        {
            ret = max(ret, a[i]+(cur==0?0:rule[node][i]) + solve(a, mask|(1<<i), i , cur+1));
        }
    }
    
    return dp[mask][node] = ret;
}

int main()
{
	memset(dp, -1, sizeof dp);
    //ifstream inf("");
    //ofstream outf("");
    //cout << setprecision(10);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> m >> k;
    
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        rule[x][y] = c;
    }
    
    cout << solve(a, 0, 0, 0) << endl;
    
    return 0;
    
}