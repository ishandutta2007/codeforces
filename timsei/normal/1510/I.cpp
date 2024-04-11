#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1100;
const ld C = 0.3;
 
mt19937 mt(48);
 
int N, M;
ld wlog[MAXN];
 
ld rand_double()
{
    int v = rand();
    int mmod = (1 << 16);
    return (ld) (v % mmod) / (ld) mmod;
}
 
void gogo()
{
    cin >> N >> M;
 
    for (int i = 0; i < N; i++)
        wlog[i] = 0;
 
    for (int i = 0; i < M; i++)
    {
        string s; cin >> s;
        ld et = 0, vt = 0;
        for (int j = 0; j < N; j++)
        {
            ld vv = exp (wlog[j]);
            vt += vv;
            if (s[j] == '1')
                et += vv;
        }
 
        if (rand_double() < et / vt)
            cout << "1\n";
        else
            cout << "0\n";
        cout << flush;
        char c;
        cin >> c;
 
        ld whi = -100;
        for (int j = 0; j < N; j++)
        {
            if (s[j] != c) wlog[j] -= C;
            whi = max (whi, wlog[j]);
        }
        for (int j = 0; j < N; j++)
            wlog[j] -= whi;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}