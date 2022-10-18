#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int n;
int a[N];

int one(int i)
{
    if(i<=1||i>=n)
        return 0;
    return a[i-1]<a[i]&&a[i]>a[i+1]||
           a[i-1]>a[i]&&a[i]<a[i+1];
}

int val(int i)
{
    return one(i-1)+one(i)+one(i+1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int res=0;
        for(int i=1;i<=n;i++)
            res+=one(i);
        int ans=res;
        for(int i=1;i<=n;i++)
        {
            res-=val(i);
            int cur=a[i];
            a[i]=a[i-1];
            ans=min(ans,res+val(i));
            a[i]=a[i+1];
            ans=min(ans,res+val(i));
            a[i]=cur;
            res+=val(i);
        }
        cout<<ans<<"\n";
    }
}