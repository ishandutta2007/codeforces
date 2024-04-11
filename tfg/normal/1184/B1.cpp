#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, b;
    cin >> s >> b;
    
    int attack[s];
    for (int i = 0; i != s; ++i)
        cin >> attack[i];
    
    pair<int, int> base[b];
    for (int i = 0; i != b; ++i)
        cin >> base[i].first >> base[i].second;
    
    sort(base, base + b);
    for (int i = 1; i != b; ++i)
        base[i].second += base[i - 1].second;
    
    for (int i = 0; i != s; ++i)
    {
        int l = -1;
        int r = b;
        
        while (r - l != 1)
        {
            int m = l + r >> 1;
            if (attack[i] >= base[m].first)
                l = m;
            else
                r = m;
        }
        
        if (l == -1)
            cout << 0 << ' ';
        else
            cout << base[l].second << ' ';
    }
    cout << '\n';
    
    return 0;
}