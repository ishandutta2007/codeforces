#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        int cnt[2]={};
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(i%2!=a%2)
                cnt[i%2]++;
        }
        if(cnt[0]==cnt[1])
            cout<<cnt[0]<<"\n";
        else
            cout<<-1<<"\n";
    }
}