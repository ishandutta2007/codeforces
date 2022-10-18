#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int A=1e7+100;

int lp[A+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> pr;
    for(int i=2;i<=A;i++)
    {
        if(!lp[i])
            lp[i]=i,
            pr.push_back(i);
        for(int p:pr)
        {
            if(p>lp[i]||p*i>A)
                break;
            lp[p*i]=p;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans=1;
        set<int> s;
        while(n--)
        {
            int x;
            cin>>x;
            int res=1;
            while(x>1)
            {
                int p=lp[x];
                int pw=0;
                while(x%p==0)
                    x/=p,
                    pw++;
                if(pw%2)
                    res*=p;
            }
            if(s.count(res))
                ans++,
                s.clear();
            s.insert(res);
        }
        cout<<ans<<"\n";
    }
}