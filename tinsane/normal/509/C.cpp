#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")
int n, th(0), la(0), tmp, tv(0);
string ans("0");

void upgrade()
{
    for(int i(ans.size() - 1); th && i >= 0; --i)
    {
        tmp = ans[i];
        ans[i] += MIN(th, '9' - ans[i]);
        th -= MIN(th, '9' - tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int T(0); T < n; ++T)
    {
        la = tv;
        cin >> th;
        tv = th;
        if(th > la)
        {
            th -= la;
            upgrade();

            while(th)
            {
                if(th > 8)
                {
                    ans = '9' + ans;
                    th -= 9;
                }
                else
                {
                    ans =( (char) ('0' + th) ) + ans;
                    th = 0;
                }
            }

        }
        else
        {
            tmp = th;
            int pos(-1);
            for(int i(0); th > 0 && i < ans.size(); ++i)
            {
                th -= ans[i] - '0';
                if(ans[i] == '9' || th <= 0)
                    continue;
                pos = i;
            }
            if(pos == -1)
            {
                th = tmp;
                --th;
                ans = '1' + ans;
                for(int i(1); i < ans.size(); ++i)
                    ans[i] = '0';
                upgrade();
            }
            else
            {
                ++ans[pos];
                th = tmp;
                for(int i(0); i <= pos; ++i)
                    th -= ans[i] - '0';
                for(int i(pos + 1); i < ans.size(); ++i)
                    ans[i] = '0';
                upgrade();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}