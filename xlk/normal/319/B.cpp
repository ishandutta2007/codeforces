#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 110000;

int f[maxn], x[maxn], S[maxn];

int main(int argc, char **argv)
{
    int n; 
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> x[i];
    int t = 0, ans = 0;
    for(int i=n;i>=1;i--)
    {
        for (; t && x[S[t]] < x[i]; --t)
            f[i] = max(f[i] + 1, f[S[t]]);
        S[++t] = i;
        if(f[i]>ans)
        	ans=f[i];
    }
    cout << ans << endl;
    return 0; 
}