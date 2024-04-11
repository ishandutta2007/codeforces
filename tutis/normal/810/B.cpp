#include <bits/stdc++.h>
using namespace std;
bool myfunction (pair<int64_t, int64_t> a,pair<int64_t, int64_t> b) {
        return ((min(2*a.first, a.second)-min(a.first, a.second))> (min(2*b.first, b.second)-min(b.first, b.second)));
     }
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int64_t n, f;
    cin >> n >> f;
    vector<pair<int64_t, int64_t> > k(n);
    for(int64_t i=0; i<n; i++)
        cin>>k[i].first>>k[i].second;
    sort(k.begin(), k.end(), myfunction);
    int64_t ats=0;
    for(int64_t i=0; i<f; i++)
    {
        ats+=min(2*k[i].first, k[i].second);
    }
    for(int64_t i=f; i<n; i++)
    {
        ats+=min(k[i].first, k[i].second);
    }
    cout<<ats;
    return 0;
}