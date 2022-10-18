#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int c2(int n)
{
    return n*(n-1)/2;
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
        int m,d,w;
        cin>>m>>d>>w;
        int k=w/__gcd(w,d-1);
        int p=min(m,d);
        int r=(p-1)%k;
        int cnt=(p-1)/k+1;
        int ans1=c2(cnt)*(r+1);
        int ans2=c2(cnt-1)*(k-r-1);
//        cout<<m<<" "<<d<<" "<<w<<" -> "<<k<<" "<<p<<" "<<r<<" "<<cnt<<" "<<ans1<<" "<<ans2<<" -> ";
        cout<<ans1+ans2<<"\n";
    }
}