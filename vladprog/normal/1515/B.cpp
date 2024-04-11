#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool sqr(int x)
{
    int s=sqrt(x);
    while(s*s<x)
        s++;
    while(s*s>x)
        s--;
    return s*s==x;
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
        cout<<(n%2==0&&sqr(n/2)||
               n%4==0&&sqr(n/4)?"YES\n":"NO\n");
    }
}