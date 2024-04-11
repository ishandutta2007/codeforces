#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int k[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    vector<pii> v;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(pair(k[i],i)>pair(k[j],j))
                v.push_back({i,j});
    sort(v.begin(),v.end(),[](pii p,pii q){return k[p.x]-k[p.y]>k[q.x]-k[q.y];});
    for(auto[i,j]:v)
    {
        cout<<"? "<<i<<" "<<j<<endl;
        string res;
        cin>>res;
        if(res=="Yes")
            cout<<"! "<<i<<" "<<j<<endl,
            exit(0);
    }
    cout<<"! "<<0<<" "<<0<<endl;
}