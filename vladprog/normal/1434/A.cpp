#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int cnt1[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[7];
    for(int i=1;i<=6;i++)
        cin>>a[i];
    int n;
    cin>>n;
    vector<pii> v;
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        for(int j=1;j<=6;j++)
            v.push_back({b-a[j],i});
    }
    sort(v.begin(),v.end());
    int cnt2=0;
    int ans=2e9;
    for(int i=0,j=-1;i<v.size();i++)
    {
        while(j+1<v.size()&&cnt2<n)
        {
            j++;
            if(!cnt1[v[j].y])
                cnt2++;
            cnt1[v[j].y]++;
        }
        if(cnt2==n)
            ans=min(ans,v[j].x-v[i].x);
        cnt1[v[i].y]--;
        if(!cnt1[v[i].y])
            cnt2--;
    }
    cout<<ans;
}