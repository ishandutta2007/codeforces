#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int p[N];

int dsu(int x)
{
    return p[x]==x?x:p[x]=dsu(p[x]);
}

void un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return;
    if(rand()&1)
        p[x]=y;
    else
        p[y]=x;
}

map<char,int> cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        s="_"+s;
        for(int i=1;i<=n;i++)
            p[i]=i,
            cnt[i].clear();
        for(int i=1,j=n;i<j;i++,j--)
            un(i,j);
        for(int i=1;i<=n-k;i++)
            un(i,i+k);
        for(int i=1;i<=n;i++)
            cnt[dsu(i)][s[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!cnt[i].empty())
            {
                multiset<int,greater<int>> cur;
                for(auto x:cnt[i])
//                    cout<<x.x<<x.y<<" ",
                    cur.insert(x.y);
                cur.erase(cur.begin());
                ans+=accumulate(cur.begin(),cur.end(),0ll);
//                cout<<"\n";
            }
        cout<<ans<<"\n";
    }
}