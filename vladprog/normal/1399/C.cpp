#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

int w[N];

int solve(int n,int s)
{
    int k=0;
    int l=1,r=n;
    while(l<r)
        if(w[l]+w[r]<s)
            l++;
        else if(w[l]+w[r]>s)
            r--;
        else
            k++,l++,r--;
    return k;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        sort(w+1,w+n+1);
        int k=0;
        for(int s=2;s<=2*n;s++)
            k=max(k,solve(n,s));
        cout<<k<<"\n";
    }
}