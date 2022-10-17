
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int maxn = 105;
const double eps = 1e-9;
struct point
{
    double x,y;
}ps[maxn];
typedef pair<double,double> pdd;
vector<pdd> vec;
int main()
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
            if(ps[i].x==ps[j].x) k=1e9,b=ps[i].x;
            else k=(ps[i].y - ps[j].y)/(ps[i].x - ps[j].x),b=ps[i].y-k*ps[i].x;
            pdd l = {k,b};
            int ok = 1;
            int tmp = 0;
            for(int i=0;i<vec.size();++i)
            {
                if(fabs(l.first-vec[i].first)>eps) ++tmp;
                else if(fabs(l.second-vec[i].second)<eps) {ok = 0;break;}
            }
            if(ok) vec.push_back(l),ans+=tmp;
        }
    }
    cout << ans << endl;
}