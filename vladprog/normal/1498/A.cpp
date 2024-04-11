#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int sum(int n)
{
    int res=0;
    while(n)
        res+=n%10,
        n/=10;
    return res;
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
        while(__gcd(n,sum(n))==1)
            n++;
        cout<<n<<"\n";
    }
}