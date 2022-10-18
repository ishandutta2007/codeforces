#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,A=210;

int a[N];
vector<int> pos[A];
int cnt[A][N];

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
        {
            for(int j=1;j<A;j++)
                cnt[j][i]=cnt[j][i-1];
            cnt[a[i]][i]++;
        }
        for(int i=1;i<A;i++)
            pos[i].clear();
        for(int i=n;i>=1;i--)
            pos[a[i]].push_back(i);
        int ans=0;
        for(int i=1;i<A;i++)
            ans=max<int>(ans,pos[i].size());
        for(int i=1;i<=n;i++)
        {
            int val=a[i];
            int x=cnt[val][i];
            int j=pos[val][x-1];
            if(i>=j)
                continue;
//            cout<<i<<" -> "<<x<<" "<<j<<" :\n";
            for(int oth=1;oth<A;oth++)
            {
                int y=cnt[oth][j-1]-cnt[oth][i];
//                if(oth<=3)
//                    cout<<"    "<<oth<<" -> "<<y<<" "<<2*x+y<<"\n";
                ans=max(ans,2*x+y);
            }
        }
        cout<<ans<<"\n";
    }
}