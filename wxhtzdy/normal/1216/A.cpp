#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(). x.rend()

void solve()
{
    int n;
    cin >> n;
    string x;
    cin >> x;
    int brojac = 0;
    for(int i = 0; i < n; i += 2)
    {
        if(x[i] == x[i+1])
        {
            brojac++;
            if(x[i] == 'a') x[i] = 'b';
            else x[i] = 'a';
        }
    }
    cout << brojac << "\n" << x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--)
        solve();
    return 0;
}