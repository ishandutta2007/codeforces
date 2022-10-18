#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,BASE=2,MOD=1e9+7,A=26;

int ppow(int x)
{
    int y=MOD-2;
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int pw[N],rev[N],h[N][A];

int get(int l,int r,int c)
{
    return (h[r][c]-h[l-1][c]+MOD)*rev[l]%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s="_"+s;
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*BASE%MOD;
    rev[n]=ppow(pw[n]);
    for(int i=n-1;i>=0;i--)
        rev[i]=rev[i+1]*BASE%MOD;
    for(int i=1;i<=n;i++)
    {
        for(int c=0;c<A;c++)
            h[i][c]=h[i-1][c];
        h[i][s[i]-'a']=(h[i][s[i]-'a']+pw[i])%MOD;
    }
    while(m--)
    {
        int x,y,len;
        cin>>x>>y>>len;
        vector<int> a;
        for(int c=0;c<A;c++)
            a.push_back(get(x,x+len-1,c));
//        for(int c=0;c<A;c++)
//            cout<<a[c]<<" ";
//        cout<<"\n";
        sort(a.begin(),a.end());
        vector<int> b;
        for(int c=0;c<A;c++)
            b.push_back(get(y,y+len-1,c));
//        for(int c=0;c<A;c++)
//            cout<<b[c]<<" ";
//        cout<<"\n";
        sort(b.begin(),b.end());
        cout<<(a==b?"YES\n":"NO\n");
    }
}