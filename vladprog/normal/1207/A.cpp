#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(int b,int p,int f,int h,int c)
{
    int cnt1=min(b/2,p);
    b-=cnt1*2;
    int cnt2=min(b/2,f);
    return cnt1*h+cnt2*c;
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
        int b,p,f,h,c;
        cin>>b>>p>>f>>h>>c;
        cout<<max(solve(b,p,f,h,c),solve(b,f,p,c,h))<<"\n";
    }
}