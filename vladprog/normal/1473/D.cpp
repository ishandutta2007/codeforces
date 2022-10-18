#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,L=20;

int pref[N],mn[N][L+1],mx[N][L+1];

int get_min(int l,int r)
{
    int len=r-l+1;
    int j=63-__builtin_clzll(len);
//    cout<<"min "<<l<<" .. "<<r<<" -> "<<len<<" "<<j<<" -> "<<min(mn[l][j],mn[r-(1<<j)+1][j])<<"\n";
    return min(mn[l][j],mn[r-(1<<j)+1][j]);
}

int get_max(int l,int r)
{
    int len=r-l+1;
    int j=63-__builtin_clzll(len);
//    cout<<"max "<<l<<" .. "<<r<<" -> "<<len<<" "<<j<<" -> "<<max(mx[l][j],mx[r-(1<<j)+1][j])<<"\n";
    return max(mx[l][j],mx[r-(1<<j)+1][j]);
}

int get_sum(int l,int r)
{
    return pref[r]-pref[l-1];
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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        s="_"+s;
        pref[0]=0;
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+(s[i]=='+'?1:-1);
        pref[n+1]=pref[n];
        for(int i=0;i<=n+1;i++)
            mn[i][0]=pref[i];
        for(int j=1;j<=L;j++)
            for(int i=0;i+(1<<j)-1<=n+1;i++)
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        for(int i=0;i<=n+1;i++)
            mx[i][0]=pref[i];
        for(int j=1;j<=L;j++)
            for(int i=0;i+(1<<j)-1<=n+1;i++)
                mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        while(m--)
        {
            int l,r;
            cin>>l>>r;
//            cout<<"in: "<<l<<" .. "<<r<<"\n";
//            cout<<"before: "<<get_min(0,l-1)<<".."<<get_max(0,l-1)<<"\n";
//            cout<<"after: "<<get_min(r+1,n+1)<<".."<<get_max(r+1,n+1)<<" - "<<get_sum(l,r)<<"\n";
//            cout<<"out: \n";
            int low=min(get_min(0,l-1),get_min(r+1,n+1)-get_sum(l,r));
            int high=max(get_max(0,l-1),get_max(r+1,n+1)-get_sum(l,r));
            cout<<high-low+1<<"\n";
        }
    }

}