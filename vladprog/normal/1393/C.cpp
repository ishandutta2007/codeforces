#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];
int cnt0[N];
int cnt[N];
int ord[N];

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
            cnt0[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            cnt0[a[i]]++;
        int l=0,r=n-1;
        while(l<r)
        {
            int m=(l+r+1)/2;
            bool ok=true;
            set<pii,greater<>> s;
            for(int i=1;i<=n;i++)
            {
                cnt[i]=cnt0[i];
                if(cnt[i]>=1)
                    s.insert({cnt[i],i});
            }
            for(int i=1;i<=n;i++)
            {
                if(s.empty())
                {
                    ok=false;
                    break;
                }
                auto p=*s.begin();
                s.erase(s.begin());
//                cout<<"- "<<p.x<<" "<<p.y<<"\n";
                ord[i]=p.y;
                cnt[p.y]--;
                int j=i-m;
                if(j>=1)
                {
                    int val=ord[j];
                    if(cnt[val]>=1)
//                        cout<<"+ "<<cnt[val]<<" "<<val<<"\n",
                        s.insert({cnt[val],val});
                }
            }
//            cout<<m<<" -> "<<(ok?"YES\n":"NO\n")<<flush;
            if(ok)
                l=m;
            else
                r=m-1;
        }
        cout<<l<<"\n";
    }
}