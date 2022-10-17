
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
const double eps = 1e-9;
struct db
{
    double d;
    db():d(0){}
    db(double d):d(d){}
    bool operator < (const db & b) const
    {
        return b.d-d>eps;
    }
    bool operator == (const db & b) const
    {
        return fabs(b.d-d)<eps;
    }
};
const int INF = 1e9;
const int maxn = 5005;
struct point
{
    int x,y;
}ps[maxn];
typedef pair<double,double> pdd;
vector<pdd> vec;
map<db,set<db>> mp1;
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        cin>>ps[i].x>>ps[i].y;
        for(int j=1;j<i;++j)
        {
            double k = 0, b = 0;
            if(ps[i].x==ps[j].x) k=1e18,b=ps[i].x;
            else k=1.0*(ps[i].y - ps[j].y)/(ps[i].x - ps[j].x),b=1.0*ps[i].y-k*ps[i].x;
            db kk(k),bb(b);
            if(mp1[kk].find(bb) == mp1[kk].end()) mp1[kk].insert(bb);
        }
    }
    int cur = 0;
    for(auto it = mp1.begin();it != mp1.end();++it)
    {
        ans += cur * mp1[it->first].size();
        cur = cur + mp1[it->first].size();
    }
    cout << ans << endl;
}