#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, x; cin >> n >> x;

        int m_diff = 0;
        int m_hit = 0;
        for (int j = 0; j < n; ++j)
        {
            int d, h; cin >> d >> h;
            m_diff = max(d - h, m_diff);
            m_hit = max(m_hit, d);
        }
        if (m_diff <= 0 && m_hit < x)
        {
            cout << -1 << endl;
        }
        else if (m_hit >= x)
            cout << 1 << endl;
        else
        {
            int num_blows = (max(0, (x - m_hit + m_diff - 1) / m_diff)) + 1;
            cout << num_blows << endl;
        }
    }
    return 0;
}