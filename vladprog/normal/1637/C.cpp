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
            cin>>a[i];
        int sum=0,cnt=0;
        multiset<int> big;
        for(int i=2;i<=n-1;i++)
        {
            sum+=a[i];
            cnt+=a[i]%2;
            if(a[i]>=2)
                big.insert(a[i]);
        }
        if(cnt&&big.empty()||
           cnt==1&&big.size()==1&&*big.begin()%2)
            cout<<-1<<"\n";
        else
            cout<<(sum+cnt)/2<<"\n";
    }
}