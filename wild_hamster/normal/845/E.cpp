#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,path_w,m;
ll num_cnt[15], sz, ans;
pii a[505];
vector<pair<pii,pii>> f;
set<ll> g;
bool cmp(pair<pii,pii> x, pair<pii,pii> y)
{
    return (x.Y < y.Y);
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (i = 0; i < k; i++)
    {
        cin >> a[i].X >> a[i].Y;
    }
    ll l = 0, r = 1000000000;
    while (l < r)
    {
        ll mid = (l+r)/2;
        f.clear();
        for (i = 0; i < k; i++)
        {
            f.push_back(mp(mp(max(a[i].X-mid,1), min(a[i].X+mid,n)),mp(max(a[i].Y-mid,1), min(a[i].Y+mid,m))));
            g.insert(f[i].X.X);
            g.insert(f[i].X.Y);
            g.insert(max(1,f[i].X.X-1));
            g.insert(min(n,f[i].X.Y+1));
        }
        sort(f.begin(), f.end(), cmp);
        /*for (i = 0; i < k; i++)
        {
            cout << f[i].X.X << " " << f[i].X.Y << " " << f[i].Y.X << " " << f[i].Y.Y << endl;
        }*/
        int minx = MOD, miny = MOD, maxx = -MOD, maxy = -MOD;
        for (auto itr = g.begin(); itr != g.end(); itr++)
        {
            int lf = 0, rg = 0;
            int val = (*itr);
            sz = val;
            if (itr == g.begin() && val > 1)
            {
                minx = 1;
                maxx = val-1;
                miny = 1;
                maxy = m;
            }
            for (i = 0; i < k; i++)
            {
                if (val >= f[i].X.X && val <= f[i].X.Y)
                {
                    if (f[i].Y.X > rg+1)
                    {
                        minx = min(minx, val);
                        maxx = max(maxx, val);
                        miny = min(miny, rg+1);
                        maxy = max(maxy, f[i].Y.X-1);
                    }
                    lf = f[i].Y.X;
                    rg = max(rg, f[i].Y.Y);
                }
            }
            if (rg < m)
            {

                maxy = m;
                miny = min(miny, rg+1);
                minx = min(minx, val);
                maxx = max(maxx, val);
            }
        }
        if (sz < n)
        {
            minx = min(minx,sz+1);
            maxx = n;
            miny = 1;
            maxy = m;
        }
        minx = max(minx, 1);
        miny = max(miny, 1);
        maxx = min(maxx, n);
        maxy = min(maxy, m);
        //cout << mid << " " << minx << " " << maxx << " " << miny << " " << maxy << endl;
        if (minx == MOD || (max(maxx-minx+1, maxy-miny+1))/2 <= mid)
        {
            r = mid;
        } else
            l = mid+1;

    }
    cout << l << endl;
    return 0;
}