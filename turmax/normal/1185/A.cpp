#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector <int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    a=v[0];
    b=v[1];
    c=v[2];
    int sum=0;
    if((b-a)<d)
    {
        sum+=(d-(b-a));
    }
    if((c-b)<d)
    {
        sum+=(d-(c-b));
    }
    cout<<sum;
    return 0;
}