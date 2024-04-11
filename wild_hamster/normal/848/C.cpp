#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 2000
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[100500], b[100500], typ[100500], x1[100500], x2[100500];
ll prv[105000], nxt[105000], prv1[100500], nxt1[100500];
set<ll> f[100500];
long long ansq[100500];
struct magical_query {
    ll del_prev, del_next, add_prev, add_next;
};
magical_query mq[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]].insert(i);
        b[i] = a[i];
    }
    for (i = 1; i <= n; i++)
    {
        f[i].insert(0);
        f[i].insert(n+1);
        for (auto itr = f[i].begin(); itr != f[i].end(); itr++)
        {
            auto itr1 = itr;
            itr1++;
            if (itr == f[i].begin() || itr1 == f[i].end())
                continue;
            auto itr2 = itr;
            itr2--;
            prv[*itr] = *itr2;
            nxt[*itr] = *itr1;
        }
    }
    for (i = 1; i <= n; i++)
        prv1[i] = prv[i], nxt1[i] = nxt[i];
    for (i = 0; i < m; i++)
    {
        cin >> typ[i] >> x1[i] >> x2[i];
        if (typ[i] == 1)
        {
            mq[i].del_prev = prv[x1[i]];
            mq[i].del_next = nxt[x1[i]];
            prv[mq[i].del_next] = mq[i].del_prev;
            nxt[mq[i].del_prev] = mq[i].del_next;
            f[a[x1[i]]].erase(x1[i]);
            a[x1[i]] = x2[i];
            f[a[x1[i]]].insert(x1[i]);
            auto itr = f[a[x1[i]]].find(x1[i]);
            itr++;
            mq[i].add_next = (*itr);
            nxt[x1[i]] = (*itr);
            prv[*itr] = x1[i];
            itr--;itr--;
            mq[i].add_prev = (*itr);
            prv[x1[i]] = (*itr);
            nxt[*itr] = x1[i];
            /*for (j = 1; j <= n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
            for (j = 1; j <= n; j++)
            {
                cout << prv[j] << " ";
            }
            cout << endl;
            for (j = 1; j <= n; j++)
            {
                cout << nxt[j] << " ";
            }
            cout << endl;*/
        }
    }
    for (i = 0; i < m; i++)
        ansq[i] = -1;
    int N = 4000;
    for (int L = 0; L < 25; L++)
        for (int R = L; R < 25; R++)
        {
            for (i = 1; i <= n; i++)
                prv[i] = prv1[i], nxt[i] = nxt1[i];
            ll l = 1, r = 1;
            long long ans = 0;
            for (i = 0; i < m; i++)
            {
                if (typ[i] == 1)
                {
                    //if (L+R == 0)
                    //cout << mq[i].del_prev << " " << mq[i].del_next << " " << mq[i].add_prev << " " << mq[i].add_next << endl;
                    int pos = x1[i];
                    if (mq[i].del_prev >= l && pos <= r)
                        ans -= (pos-mq[i].del_prev);
                    if (mq[i].del_next <= r && pos >= l)
                        ans -= (mq[i].del_next-pos);
                    if (mq[i].del_next <= r && mq[i].del_prev >= l)
                        ans += (mq[i].del_next-mq[i].del_prev);
                    nxt[mq[i].del_prev] = mq[i].del_next;
                    prv[mq[i].del_next] = mq[i].del_prev;

                    if (mq[i].add_prev >= l && pos <= r)
                        ans += (pos-mq[i].add_prev);
                    if (mq[i].add_next <= r && pos >= l)
                        ans += (mq[i].add_next-pos);
                    if (mq[i].add_next <= r && mq[i].add_prev >= l)
                        ans -= (mq[i].add_next-mq[i].add_prev);
                    nxt[mq[i].add_prev] = pos;
                    prv[mq[i].add_next] = pos;
                    prv[pos] = mq[i].add_prev;
                    nxt[pos] = mq[i].add_next;
                } else
                {
                    int curL = x1[i], curR = x2[i];
                    if (curL >= N*L+1 && curL < N*L+N+1 && curR >= N*R+1 && curR < N*R+N+1)
                    {
                        while (curL < l)
                        {
                            l--;
                            if (nxt[l] <= r)
                                ans += nxt[l]-l;
                        }
                        while (curR > r)
                        {
                            r++;
                            if (prv[r] >= l)
                                ans += r-prv[r];
                        }
                        while (curL > l)
                        {
                            if (nxt[l] <= r)
                                ans -= nxt[l]-l;
                            l++;
                        }
                        while (curR < r)
                        {
                            if (prv[r] >= l)
                                ans -= r-prv[r];
                            r--;
                        }
                        ansq[i] = ans;
                        //cout << l << " " << r << endl;
                    }
                }
            }
        }
    for (i = 0; i < m; i++)
        if (typ[i] == 2)
            cout << ansq[i] << endl;
    return 0;
}