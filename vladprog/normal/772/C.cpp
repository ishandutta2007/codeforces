#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int gcd (int a, int b, int & x, int & y)
{
	if (a == 0)
    {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int rev(int a,int m)
{
    int x, y;
    int g = gcd (a, m, x, y);
    assert(g==1);
    x = (x % m + m) % m;
    return x;
}

const int N=2e5+100;

bool ok[N];
int dp[N],nxt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        ok[i]=true;
    while(n--)
    {
        int x;
        cin>>x;
        ok[x]=false;
    }
    for(int d=m;d>=1;d--)
        if(m%d==0)
        {
            for(int x=2*d;x<=m;x+=d)
                if(m%x==0&&(dp[x]>dp[d]))
                    nxt[d]=x,
                    dp[d]=dp[x];
            for(int x=0;x<m;x+=d)
                if(ok[x]&&__gcd(m/d,x/d)==1)
                    dp[d]++;
//            cout<<d<<" -> "<<dp[d]<<"\n";
        }
    cout<<dp[1]<<"\n";
    int p=1;
    int prev_d=1;
    for(int d=1;d;d=nxt[d])
        for(int x=0;x<m;x+=d)
            if(ok[x]&&__gcd(m/d,x/d)==1)
//                cout<<x<<":",
                cout<<x/prev_d*rev(p/prev_d,m/prev_d)%m<<" ",
                p=x,
                prev_d=d;
}