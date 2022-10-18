#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int A=1e6+100;
int lp[A+1];
int x[A+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    x[1]=1;
    vector<int> pr;
    for(int i=2;i<=A;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            x[i]=i,
            pr.push_back(i);
        for(int p:pr)
        {
            if(p*i>A||p>lp[i])
                break;
            lp[p*i]=p;
            if(x[i]%p==0)
                x[p*i]=x[i]/p;
            else
                x[p*i]=x[i]*p;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> cnt;
        while(n--)
        {
            int a;
            cin>>a;
            cnt[x[a]]++;
//            cout<<x[a]<<" ";
        }
//        cout<<"\n";
        int ans0=0;
        int ans1=0;
        for(auto[a,c]:cnt)
        {
            ans0=max(ans0,c);
            if(a==1||c%2==0)
                ans1+=c;
        }
        ans1=max(ans0,ans1);
        int q;
        cin>>q;
        while(q--)
        {
            int w;
            cin>>w;
            if(w==0)
                cout<<ans0<<"\n";
            else
                cout<<ans1<<"\n";
        }
    }
}