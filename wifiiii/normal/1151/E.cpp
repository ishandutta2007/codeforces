
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    ll ans = 0;
    int last = 0;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin >> tmp;
        ans += 1LL * tmp * (n - tmp + 1);
        int m = min(tmp, last), M = max(tmp, last);
        ans -= 1LL * m * (n - M + 1);
        last = tmp;
    }
    cout << ans << endl;
}