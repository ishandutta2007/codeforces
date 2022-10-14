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
//#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,q,r,timer,mx;

ll a[100500];
vector<ll> f;
string myf(ll h, ll m, ll s, ll t1, ll t2)
{
    if (m == 0 && s == 0)
        h *= 2;
    else
        h = h*2+1;
    h %= 24;
    if (s == 0)
    {
        if (m%5 == 0)
            m = m*2/5;
        else
            m = (m/5)*2+1;
    } else
        m = (m/5)*2+1;
    if (s%5 == 0)
        s = s*2/5;
    else
        s = (s/5)*2+1;
    m %= 24;
    s %= 24;
    t1 *= 2;
    t2 *= 2;
    if (t1 == m || t1 == s || t1 == h || t2 == m || t2 == s || t2 == h)
        return "HYU";
    m+=24;
    s+=24;
    h+=24;
    if (t1 == m || t1 == s || t1 == h || t2 == m || t2 == s || t2 == h)
        return "HYU";
    m-=24;
    s-=24;
    h-=24;
    f.clear();
    f.push_back(m);
    f.push_back(s);
    f.push_back(h);
    sort(f.begin(), f.end());
    for (i = 0; i < 2; i++)
        if (t1 > f[i] && t1 < f[i+1] && t2 > f[i] && t2 < f[i+1])
    {
        return "YES";
    }
    if (t1 > f[2] && t1 < f[0]+24 && t2 > f[2] && t2 < f[0]+24 ||
        t1+24 > f[2] && t1+24 < f[0]+24 && t2 > f[2] && t2 < f[0]+24 ||
        t1 > f[2] && t1 < f[0]+24 && t2+24 > f[2] && t2+24 < f[0]+24 ||
        t1+24 > f[2] && t1+24 < f[0]+24 && t2+24 > f[2] && t2+24 < f[0]+24)
    {
        return "YES";
    }
    return "NO";

}
string hisf(ll h, ll m, ll s, ll t1, ll t2)
{
    int a,b,c;
    a=h;b=m/5;c=s/5;
    vector<int>vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(),vec.end());
    int d = vec[0]+12;
    vec.push_back(d);
    for (int i = 0; i < 3; i++)
    {
        if (t1 > vec[i] && t1<=vec[i+1] && t2 > vec[i] && t2 <= vec[i+1])
            return "YES";
        if (t1+12 > vec[i] && t1+12<=vec[i+1] && t2 > vec[i] && t2 <= vec[i+1])
            return "YES";
        if (t1 > vec[i] && t1<=vec[i+1] && t2+12 > vec[i] && t2+12 <= vec[i+1])
            return "YES";
        if (t1+12 > vec[i] && t1+12<=vec[i+1] && t2+12 > vec[i] && t2+12 <= vec[i+1])
            return "YES";
    }
    return "NO";
}
int main() {
    //freopen("input.txt","r",stdin);
    srand(time(0));

    ll h,m,s,t1,t2;
    cin >> h >> m >> s >> t1 >> t2;
    cout << myf(h,m,s,t1,t2);
    return 0;
}