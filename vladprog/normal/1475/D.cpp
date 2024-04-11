#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e9;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> one,two;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            if(b[i]==1)
                one.push_back(a[i]);
            else
                two.push_back(a[i]);
        sort(one.begin(),one.end(),greater<>());
        sort(two.begin(),two.end(),greater<>());
        int best=INF;
        for(int i=-1,j=-1,suma=0,sumb=0;i<int(one.size());i++)
        {
            if(i>=0)
                suma+=one[i],
                sumb++;
            while(j>=0&&suma-two[j]>=m)
                suma-=two[j--],
                sumb-=2;
            while(j+1<int(two.size())&&suma<m)
                suma+=two[++j],
                sumb+=2;
            if(suma>=m)
                best=min(best,sumb);
        }
        if(best==INF)
            best=-1;
        cout<<best<<"\n";
    }
}