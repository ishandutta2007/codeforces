#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int u[N],v[N],cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
        cin>>u[i]>>v[i],
        cnt[u[i]]++,
        cnt[v[i]]++;
    vector<int> leaf;
    for(int i=1;i<=n;i++)
        if(cnt[i]==1)
            leaf.push_back(i);
    if(leaf.size()==2)
    {
        for(int i=0;i<=n-2;i++)
            cout<<i<<"\n";
        exit(0);
    }
    for(int i=1,j=3;i<=n-1;i++)
        if(u[i]==leaf[0]||v[i]==leaf[0])
            cout<<0<<"\n";
        else if(u[i]==leaf[1]||v[i]==leaf[1])
            cout<<1<<"\n";
        else if(u[i]==leaf[2]||v[i]==leaf[2])
            cout<<2<<"\n";
        else
            cout<<j++<<"\n";
}