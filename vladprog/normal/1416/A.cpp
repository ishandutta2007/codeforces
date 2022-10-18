#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int a[N];
vector<int> v[N];
int res[N];

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
            v[i]={0,n+1};
        for(int i=1;i<=n;i++)
            v[a[i]].push_back(i);
        for(int i=1;i<=n;i++)
            res[i]=N;
        for(int i=n;i>=1;i--)
        {
            int d=-1;
            sort(v[i].begin(),v[i].end());
            for(int j=0;j+1<v[i].size();j++)
                d=max(d,v[i][j+1]-v[i][j]);
            res[d]=i;
        }
        int ans=N;
        for(int i=1;i<=n;i++)
            ans=min(ans,res[i]),
            cout<<(ans==N?-1:ans)<<" ";
        cout<<"\n";
    }
}