#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<int> s[20];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<20;j++)
            if((a[i]>>j)&1)
                s[j].insert(i);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<20;j++)
        {
            if(s[j].empty())
                continue;
            int k=*s[j].begin();
            s[j].erase(s[j].begin());
            if(k==i)
                continue;
            int x=a[i],y=a[k];
            for(int t=0;t<20;t++)
                if(((x>>t)&1)==0&&
                   ((y>>t)&1)==1)
                    s[t].erase(k),
                    s[t].insert(i);
            s[j].erase(i);
            a[i]=x|y;
            a[k]=x&y;
        }
//    for(int i=1;i<=n;i++)
//        cout<<a[i]<<" ";
//    cout<<"\n";
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=a[i]*a[i];
    cout<<ans;
}