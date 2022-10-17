#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int px[5005], py[5005];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int x = 0, y = 0, n = s.size();
        for(int i = 1; i <= n; ++i)
        {
            char c = s[i-1];
            if(c == 'L')
            {
                --x;
            }
            else if(c == 'R')
            {
                ++x;
            }
            else if(c == 'D')
            {
                --y;
            }
            else if(c == 'U')
            {
                ++y;
            }
            px[i] = x;
            py[i] = y;
        }
        auto chk = [&](int dx, int dy) -> int
        {
            int x = 0, y = 0;
            for(char c : s)
            {
                if(c == 'L')
                {
                    if(dy != y || x - 1 != dx) --x;
                }
                else if(c == 'R')
                {
                    if(dy != y || x + 1 != dx) ++x;
                }
                else if(c == 'D')
                {
                    if(dx != x || y - 1 != dy) --y;
                }
                else if(c == 'U')
                {
                    if(dx != x || y + 1 != dy) ++y;
                }
            }
            return x == 0 && y == 0;
        };
        int ok = 0;
        for(int i=1;i<=n;++i)
        {
            if(chk(px[i], py[i]))
            {
                ok = 1;
                cout << px[i] << ' ' << py[i] << endl;
                break;
            }
        }
        if(!ok) cout << 0 << " " << 0 << endl;
    }
}