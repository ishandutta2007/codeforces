#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=310;

pii a[N];
int place[N];
bool used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        #define n reignbdf
        for(int i=1;i<=m;i++)
            cin>>a[i].x,a[i].y=-i;
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++)
            place[-a[i].y]=i;
//        for(int i=1;i<=m;i++)
//            cout<<place[i]<<" ";
//        cout<<" -> ";
        memset(used,0,m+10);
        int ans=0;
        for(int i=1;i<=m;i++)
            ans+=accumulate(used+1,used+place[i],0ll),
            used[place[i]]=true;
        cout<<ans<<"\n";
    }
}