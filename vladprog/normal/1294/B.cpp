#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=1010;

pair<int,int> p[N];

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
            cin>>p[i].first>>p[i].second;
        sort(p+1,p+n+1);
        string s;
        bool ok=true;
        for(int i=1;i<=n;i++)
            if(p[i].first<p[i-1].first||p[i].second<p[i-1].second)
                ok=false;
            else
                s+=string(p[i].first-p[i-1].first,'R')+string(p[i].second-p[i-1].second,'U');
        if(ok)
            cout<<"YES\n"<<s<<"\n";
        else
            cout<<"NO\n";
    }
}