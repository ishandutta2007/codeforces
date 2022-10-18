#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,int> cnt1;
    map<pii,int> cnt2;
    while(n--)
    {
        int w,h;
        cin>>w>>h;
        if(w>h)
            swap(w,h);
        if(w==h)
            cnt1[w]++;
        else
            cnt1[w]++,
            cnt1[h]++,
            cnt2[{w,h}]++;
    }
    int ans=0;
    for(auto[x,y]:cnt1)
        ans+=y*(y-1)/2;
    for(auto[x,y]:cnt2)
        ans-=y*(y-1)/2;
    cout<<ans;
}