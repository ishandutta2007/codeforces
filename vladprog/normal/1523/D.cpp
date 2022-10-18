#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,P=15;

int a[N],sos[1<<P];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0)^int(new char));

    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int mask=0;
        for(int j=0;j<m;j++)
            if(s[j]=='1')
                mask|=1LL<<j;
        a[i]=mask;
    }
    int best_mask=0,
        best_cnt=0,
        n2=(n+1)/2;
    while(clock()*1.0/CLOCKS_PER_SEC<2.8)
    {
        int inter=a[(rand()*(RAND_MAX+1)+rand())%n+1];
        vector<int> bits;
        for(int j=0;j<m;j++)
            if((inter>>j)&1)
                bits.push_back(j);
//        for(int b:bits) cout<<b<<" ";
//        cout<<endl;
        memset(sos,0,sizeof(sos));
        for(int i=1;i<=n;i++)
        {
            int compress=0;
            for(int j=0;j<bits.size();j++)
                if(!((a[i]>>bits[j])&1))
                    compress|=1<<j;
            sos[compress]++;
        }
        for(int i = 0;i < bits.size(); ++i)
            for(int mask = 0; mask < (1<<bits.size()); ++mask)
                if(mask & (1<<i))
                    sos[mask] += sos[mask^(1<<i)];
        for(int mask=0;mask<(1<<bits.size());mask++)
            if(sos[mask]>=n2)
            {
                int cnt=bits.size()-__builtin_popcount(mask);
                if(cnt>best_cnt)
                {
                    best_cnt=cnt;
                    best_mask=0;
                    for(int j=0;j<bits.size();j++)
                        if(!((mask>>j)&1))
                            best_mask|=1LL<<bits[j];
                }
            }
    }
    for(int i=0;i<m;i++)
        if((best_mask>>i)&1)
            cout<<'1';
        else
            cout<<'0';
}