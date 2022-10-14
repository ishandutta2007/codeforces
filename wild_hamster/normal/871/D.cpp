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
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[200500],b[250005], c[200500];
ll pre_bits[1500];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}
const int N = 10000005;
int lp[N+5];
vector<int> pr;
vector<int> factors;
int prs[N+5], sumprs[N+5];
void factorize(int x) {
    int k = 0;
    while (x != 1) {
        factors.push_back(lp[x]);
        int i = lp[x];
        while (x%i == 0)
            x /= i;
        k++;
    }
    //cout << k << endl;

}

int main() {
    //freopen("input.txt","r",stdin);

    cin >> n;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);


        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 2; i <= n; i++)
    {
        prs[lp[i]]++;

    }
    for (int i = 2; i <= n; i++)
        sumprs[i] = sumprs[i-1] + prs[i];
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    if (!prs[i] || i <= n/2) {
        factors.clear();
        factorize(i);
        int min_div = lp[i];
        int sz = factors.size();
        int cnt = 0;
        for (int i = 1; i < (1<<sz); i++)
        {
            ll bits_cnt = 0;
            ll cur = n;
            for (int j = 0; j < sz; j++)
                if ((i&(1<<j)) != 0)
                {
                    cur /= factors[j];
                    bits_cnt++;
                }
            if (bits_cnt&1)
                cnt += cur;
            else
                cnt -= cur;
        }
        int tot = n-1;
        int cnt0 = sumprs[n]-sumprs[n/2];
        int cnt3 = sumprs[n/2] - sumprs[n/min_div];

        if (prs[i]) {
            if (i >= n/min_div+1 && i <= n/2)
                cnt3--;
        }
        ans += cnt-1 + cnt3*3 + (tot-cnt0-cnt3-cnt)*2;
        //if (prs[i] && )
    }
    cout << ans/2 << endl;
    return 0;
}