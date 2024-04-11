#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=1e9-63;
//const int BASE=10;
const int BASE=1e6+3;

int p[N],r[N],t[N],h[N],pref[N],sz[N],lef[N],rig[N];

int ppow(int x,int y)
{
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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p[0]=1;
    for(int i=1;i<N;i++)
        p[i]=p[i-1]*BASE%MOD;
    r[N-1]=ppow(p[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        r[i]=r[i+1]*BASE%MOD;
    t[0]=0;
    for(int i=1;i<N;i++)
        t[i]=t[i-1]+p[i-1];

    int n;
    cin>>n;
    string s;
    cin>>s;
    s="_"+s;
    vector<int> v;
    int cur=0,cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
            cnt1=0,
            cnt0++;
        else
        {
            if(cnt1%2)
                cur-=p[v.size()-1]*v.back(),
                v.pop_back();
            cnt1++;
            if(cnt1%2)
                v.push_back(cnt0),
                cur+=p[v.size()-1]*v.back();
        }
        pref[i]=cnt0;
        cur%=MOD;
        cur+=MOD;
        cur%=MOD;
        h[i]=cur;
        sz[i]=v.size();
//        cout<<i<<" : "<<h[i]<<" "<<sz[i]<<" "<<pref[i]<<"\n";
    }
    for(int i=1;i<=n;i++)
        lef[i]=(s[i]=='0'?0:lef[i-1]+1);
    for(int i=n;i>=1;i--)
        rig[i]=(s[i]=='0'?0:rig[i+1]+1);
    int q;
    cin>>q;
    while(q--)
    {
        int l1,l2,len;
        cin>>l1>>l2>>len;

        int r1=l1+len-1;
        l1--;
        int c1=pref[r1]-pref[l1];
        bool mul1=false;
        if(lef[l1]%2&&rig[l1+1]%2)
            l1-=lef[l1],
            mul1=true;
        int h1=(((h[r1]-h[l1])*r[sz[l1]]-pref[l1]*t[sz[r1]-sz[l1]])%MOD+MOD)%MOD;
        if(mul1)
            h1=h1*BASE%MOD;


        #define l1 l2
        #define r1 r2
        #define h1 h2
        #define mul1 mul2
        #define c1 c2
        int r1=l1+len-1;
        l1--;
        int c1=pref[r1]-pref[l1];
        bool mul1=false;
        if(lef[l1]%2&&rig[l1+1]%2)
            l1-=lef[l1],
            mul1=true;
        int h1=(((h[r1]-h[l1])*r[sz[l1]]-pref[l1]*t[sz[r1]-sz[l1]])%MOD+MOD)%MOD;
        if(mul1)
            h1=h1*BASE%MOD;
        #undef l1
        #undef r1
        #undef h1
        #undef mul1
        #undef c1

//        cout<<h1<<" "<<h2<<"\n";
        cout<<(!c1&&!c2||c1==c2&&h1==h2?"Yes\n":"No\n");
    }
}

/**

10
0101011010
1
2 7 3

*/