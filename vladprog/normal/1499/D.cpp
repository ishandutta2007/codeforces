#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int A=2e7+100;

int lp[A+1],cnt[A+1];
int c,d,x,ans;
vector<pii> fact;

void divs(int i,int y)
{
    if(i==fact.size())
    {
        if((y+d)%c==0)
            ans+=cnt[(y+d)/c];
        return;
    }
    for(int j=0;j<=fact[i].y;j++)
    {
        divs(i+1,y);
        y*=fact[i].x;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> pr;
    cnt[1]=1;
    for(int i=2;i<=A;i++)
    {
        if(!lp[i])
            lp[i]=i,
            pr.push_back(i),
            cnt[i]=2;
        for(int p:pr)
        {
            if(p>lp[i]||p*i>A)
                break;
            lp[p*i]=p;
            cnt[p*i]=(p==lp[i]?cnt[i]:cnt[i]*2);
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        cin>>c>>d>>x;
        int t=x;
        fact.clear();
        while(t>1)
        {
            int p=lp[t],k=0;
            while(lp[t]==p)
                t/=p,k++;
            fact.push_back({p,k});
        }
        ans=0;
        divs(0,1);
        cout<<ans<<"\n";
    }
}