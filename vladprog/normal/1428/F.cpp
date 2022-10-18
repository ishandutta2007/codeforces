#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

string s;
int ans=0;
int dp[N];

void solve(int l,int r)
{
    bool all1=true;
    for(int i=l;i<=r;i++)
        if(s[i]=='0')
            all1=false;
    if(all1)
    {
        int add=0;
        for(int i=l;i<=r;i++)
            add+=(i-l+1)*(i-l+2)/2;
//        cout<<l<<" "<<r<<" -> "<<add<<"\n";
        ans+=add;
        return;
    }
    if(l==r)
        return;
    int m=(l+r)/2;
    int x=m;
    while(x>=l&&s[x]=='1'&&s[x+1]=='1')
        x--;
    if(x<l)
        x=-1e9;
    int y=m;
    while(y<r&&s[y]=='1'&&s[y+1]=='1')
        y++;
    if(y==r)
        y=1e9;
    assert(x>=l||y<r);
    if(m-x<y-m)
        m=x;
    else
        m=y;
    solve(l,m);
    solve(m+1,r);
    int mx=0,cur=0;
    for(int i=m;i>=l;i--)
    {
        if(s[i]=='1')
            cur++;
        else
            cur=0;
        mx=max(mx,cur);
        dp[i]=mx;
    }
    mx=0,cur=0;
    for(int i=m+1;i<=r;i++)
    {
        if(s[i]=='1')
            cur++;
        else
            cur=0;
        mx=max(mx,cur);
        dp[i]=mx;
    }
    int add=0;
    for(int i=m,j=m;i>=l;i--)
    {
        while(j+1<=r&&dp[j+1]<=dp[i])
            j++;
        add+=(j-m)*dp[i];
    }
    for(int j=m+1,i=m+1;j<=r;j++)
    {
        while(i-1>=l&&dp[i-1]<dp[j])
            i--;
        add+=(m-i+1)*dp[j];
    }
    ans+=add;
//    cout<<l<<" "<<r<<" -> "<<add<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>s;
    solve(0,n-1);
    cout<<ans;
}