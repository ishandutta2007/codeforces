#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int A=1e7+100,N=5e5+100;

int lp[A+1],val[A+1];
int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> pr;
    for(int i=2;i<=A;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            pr.push_back(i),
            val[i]=i;
        for(int p:pr)
        {
            if(i*p>A||p>lp[i])
                break;
            lp[i*p]=p;
            val[i*p]=(lp[i]==p?val[i]*p:p);
        }
    }

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(val[a[i]]==a[i])
            cout<<-1<<" ";
        else
            cout<<val[a[i]]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
        if(val[a[i]]==a[i])
            cout<<-1<<" ";
        else
            cout<<a[i]/val[a[i]]<<" ";
}