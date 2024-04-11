#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=550;

int a[N],b[N];

vector<pii> calc(int*fir,int*las)
{
    las--;
    vector<pii> res;
    for(;fir!=las&&fir!=las+1;fir++,las--)
    {
        pii p{*fir,*las};
        if(p.x>p.y)
            swap(p.x,p.y);
        res.push_back(p);
    }
    if(fir==las)
        res.push_back({-1,*fir});
    sort(res.begin(),res.end());
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        cout<<(calc(a+1,a+n+1)==calc(b+1,b+n+1)?"Yes\n":"No\n");
    }
}