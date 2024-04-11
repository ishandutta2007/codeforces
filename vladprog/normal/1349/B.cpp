#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

bool solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool is_k=false;
    for(int i=1;i<=n;i++)
        if(a[i]==k)
            is_k=true;
    if(!is_k)
        return false;
    if(n==1)
        return true;
    for(int i=1;i<=n-1;i++)
        if(a[i]>=k&&a[i+1]>=k)
            return true;
    for(int i=1;i<=n-2;i++)
        if(a[i]>=k&&a[i+2]>=k)
            return true;
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        cout<<(solve()?"yes\n":"no\n");
}