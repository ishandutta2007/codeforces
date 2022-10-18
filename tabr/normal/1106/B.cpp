#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define caseout(i, x) cout << "Case #" << i << ": " << x << endl;

bool cmp(pair<int, ll> a, pair<int, ll> b)
{
    if (a.second == b.second)
        return a < b;
    return a.second < b.second;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1), c(n + 1);
    vector<bool> b(n + 1);

    rep(i, n) cin >> a[i + 1];
    rep(i, n) cin >> c[i + 1];

    vector<pair<int, ll>> x(n);
    rep(i, n)
    {
        x[i].first = i;
        x[i].second = c[i + 1];
    }
    sort(x.begin(), x.end(), cmp);

    deque<int>y(n);
    rep(i, n) y[i]=x[i].first+1;

    rep(j, m)
    {
        int t;
        ll d, ans = 0;
        cin >> t >> d;

        if (a[t] >= d)
        {
            a[t] -= d;
            cout << d * c[t] << endl;
            continue;
        }

        ans = a[t] * c[t];
        d -= a[t];
        a[t] = 0;


        rep(i, y.size())
        {
            if (a[y[i]] == 0)
                continue;

            if (a[y[i]] >= d)
            {
                a[y[i]] -= d;
                ans += c[y[i]] * d;
                d = 0;
                cout << ans << endl;
                break;
            }

            d -= a[y[i]];
            ans += c[y[i]] * a[y[i]];
            a[y[i]] = 0;
        }

        if(d>0)
            rep(i, m - j) {
                cout << '0' << endl;
                break;
            }
        
        if(y.size()!=0)while(a[y.front()]==0){
            y.pop_front();
            if(y.size()==0)
                break;
        }
    }

    return 0;
}