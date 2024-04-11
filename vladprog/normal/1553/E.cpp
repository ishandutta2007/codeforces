#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int n,p[N],q[N];

int calc(int k)
{
    int res=0;
    for(int i=1;i<=n;i++)
        while(true)
        {
            int where=(q[i]+k-1)%n+1;
            if(where==i)
                break;
            else
                swap(q[i],q[where]),
                res++;
        }
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
        int m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        map<int,int> cnt;
        for(int i=1;i<=n;i++)
            cnt[(i-p[i]+n)%n]++;
        vector<int> ans;
        for(auto[k,c]:cnt)
            if(c>=n-2*m)
            {
                copy(p+1,p+n+1,q+1);
                if(calc(k)<=m)
                    ans.push_back(k);
            }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<" ";
        for(int x:ans)
            cout<<x<<" ";
        cout<<"\n";
    }
}