#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int lp[N+1];
int pref[N+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> pr;
    for(int i=2;i<=N;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            pr.push_back(i);
        for(int p:pr)
        {
            if(p*i>N||p>lp[i])
                break;
            lp[p*i]=p;
        }
    }
    for(int i=1;i<=N;i++)
        pref[i]=pref[i-1]+(lp[i]==i);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=sqrt(n);
        while(s*s<n)
            s++;
        while(s*s>n)
            s--;
        cout<<pref[n]-pref[s]+1<<"\n";
    }
}