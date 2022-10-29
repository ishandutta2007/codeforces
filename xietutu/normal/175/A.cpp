#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define inf 100000000;
using namespace std;
int n;
string s;
int cal(int l,int r)
{
    if (r - l !=0 && s[l - 1] == '0') return -inf;
    int now = 0;
    for (int i = l; i <= r; i++)
    {
        now = now *10 +s[i - 1] - 48;
        if (now > 1000000) return -inf;
        }
    return now;
}
int main()
{
    cin >> s;
    int ans = -inf;
    n = s.length();
    for (int i = 1; i < n; i++)
        for (int j = i + 1;j < n; j++)
        {
            int k = cal(1,i);
            if (k <0) continue;
            k += cal(i + 1,j);
            if (k < 0) continue;
            k += cal(j+1,n);
            if (k < 0 ) continue;
            //cout << k;
            ans = max(ans,k);
        }
    if (ans < 0 ) ans = -1;
    cout << ans;
    return 0;
}