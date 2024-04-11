#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<long long,long long> > b (100005);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define int long long
    int n,k;
    cin>>n;
    vector <int> a;
    for(int i=0;i<2*n;++i)
    {
        cin>>k;
        if(b[k-1].first==0)
        {
            b[k-1].first=i;
        }
        else
        {
            b[k-1].second=i;
        }
        a.push_back(k);
    }
    int sum=0;
    for(int i=1;i<n;++i)
    {
        sum+=min(abs(b[i].first-b[i-1].first)+abs(b[i].second-b[i-1].second),abs(b[i].second-b[i-1].first)+abs(b[i].first-b[i-1].second));
    }
    sum+=b[0].first;
    sum+=b[0].second;
    cout<<sum<<endl;
    return 0;
}