#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e7+100;

int lp[N+1],d[N+1],mul[N+1],add[N+1],ans[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    d[1]=1;
    ans[1]=1;
    vector<int> pr;
    for(int i=2;i<=N;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            d[i]=i+1,
            mul[i]=i+1,
            add[i]=i,
            pr.push_back(i);
//        cout<<i<<" -> "<<lp[i]<<" "<<d[i]<<" "<<mul[i]<<" "<<add[i]<<"\n";
        if(d[i]<=N&&!ans[d[i]])
            ans[d[i]]=i;
        for(int p:pr)
        {
            if(p>lp[i]||p*i>N)
                break;
            lp[p*i]=p;
            if(p==lp[i])
                add[p*i]=add[i]*p,
                mul[p*i]=mul[i]+add[p*i],
                d[p*i]=d[i]/mul[i]*mul[p*i];
            else
                add[p*i]=p,
                mul[p*i]=p+1,
                d[p*i]=d[i]*mul[p*i];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        if(ans[c])
            cout<<ans[c]<<"\n";
        else
            cout<<-1<<"\n";
    }
}