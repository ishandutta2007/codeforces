#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

multiset<int> s[40];
ll sum[40];
int f(int x)
{
    int k=0;
    while((1<<k) <= x) ++k;
    --k;
    return k;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        char c;int x;
        cin>>c>>x;
        if(c=='+')
        {
            s[f(x)].insert(x);
            sum[f(x)]+=x;
        }
        else
        {
            s[f(x)].erase(s[f(x)].find(x));
            sum[f(x)]-=x;
        }
        int ans=0;
        ll tmp=0;
        for(int i=0;i<=32;++i)
        {
            ans+=s[i].size();
            if(s[i].size() && *s[i].lower_bound(0)>2*tmp) ans--;
            tmp+=sum[i];
        }
        cout<<ans<<"\n";
    }
}