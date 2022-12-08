
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[200005],b[200005],dq[2000005],head=0,tail=0;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    for(int i=1;i<=n;++i)
    {
        if(b[i]==1)
        {
            int ok = 1;
            for(int j=i+1;j<=n;++j) if(b[j]-b[j-1]!=1) {ok=0;break;}
            if(ok)
            {
                int now = b[n] + 1;
                int ok2 = 1;
                for(int j=1;j<i;++j)
                {
                    if(b[j] && b[j] - now < j) {ok2=0;break;}
                }
                if(ok2)
                {
                    cout << n - now + 1 << endl;
                    return 0;
                }
            }
            break;
        }
    }
    
    
    int lo=0,hi=n;
    while(lo<hi)
    {
        int m=(lo+hi)/2;
        int ok = 1;
        for(int i=m;i<=n;++i)
        {
            if(b[i] && i-m>=b[i]) {ok=0;break;}
        }
        if(ok) hi=m;
        else lo=m+1;
    }
    cout<<lo+n<<endl;
}