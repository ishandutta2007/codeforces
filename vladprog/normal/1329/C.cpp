#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int H=21,N=1<<H;

int a[N],level[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    level[1]=1;
    for(int i=2;i<N;i++)
        level[i]=level[i/2]+1;
    int t;
    cin>>t;
    while(t--)
    {
        int h,g;
        cin>>h>>g;
        int n=(1<<h)-1,k=(1<<g)-1;
        for(int i=1;i<=2*n+1;i++)
            a[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vector<int> ans;
        set<pii,greater<pii>> s{{a[1],1}};
        while(s.begin()->x)
        {
            int v=s.begin()->y;
            s.erase(s.begin());
            int i=v;
            bool ok;
            while(true)
            {
                int l=2*i,r=2*i+1;
                if(a[l]==0&&a[r]==0)
                {
                    ok=level[i]>g;
                    break;
                }
                if(a[l]>a[r])
                    i=l;
                else
                    i=r;
            }
            if(ok)
            {
                ans.push_back(v);
                i=v;
                while(true)
                {
                    int l=2*i,r=2*i+1;
                    if(a[l]==0&&a[r]==0)
                    {
//                        cout<<v<<" -> "<<i<<"\n";
                        a[i]=0;
                        break;
                    }
                    if(a[l]>a[r])
                        a[i]=a[l],
                        i=l;
                    else
                        a[i]=a[r],
                        i=r;
                }
                s.insert({a[v],v});
            }
            else
                s.insert({a[2*v],2*v}),
                s.insert({a[2*v+1],2*v+1});
        }
        cout<<accumulate(a+1,a+k+1,0ll)<<"\n";
        for(int x:ans)
            cout<<x<<" ";
        cout<<"\n";
    }
}