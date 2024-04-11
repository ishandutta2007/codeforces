#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int read()
{
    char c;
    cin>>c>>c;
    string s;
    cin>>s;
    while(s.size()<4)
        s+='0';
    int res=stoi(s);
//    int res=rand()%10000;
    return res;
}

map<tuple<int,int,int>,double> mem;

double dfs(int a,int b,int c,int v)
{
    int g=__gcd(__gcd(a,b),__gcd(c,v));
    a/=g,b/=g,c/=g,v/=g;
    if(mem.count({a,b,c}))
        return mem[{a,b,c}];
    double ans=0;
    int x,y,z;
    v*=2;

    x=2*a,y=2*b,z=2*c;
    #define cur x
    if(cur!=0)
    {
        int cnt=(x!=0)+(y!=0)+(z!=0)-1;
        int dec=min(cur,v);
        cur-=dec;
//        if(x!=0) x+=dec/cnt;
        if(y!=0) y+=dec/cnt;
        if(z!=0) z+=dec/cnt;
        ans+=(1+dfs(x,y,z,v))*a/(a+b+c);
    }

    x=2*a,y=2*b,z=2*c;
    #define cur y
    if(cur!=0)
    {
        int cnt=(x!=0)+(y!=0)+(z!=0)-1;
        int dec=min(cur,v);
        cur-=dec;
        if(x!=0) x+=dec/cnt;
//        if(y!=0) y+=dec/cnt;
        if(z!=0) z+=dec/cnt;
        ans+=(1+dfs(x,y,z,v))*b/(a+b+c);
    }

//    x=a,y=b,z=c;
//    #define cur z
//    if(cur!=0)
//    {
//        int cnt=(x!=0)+(y!=0)+(z!=0)-1;
//        int dec=min(cur,v);
//        cur-=dec;
//        if(x!=0) x+=dec/cnt;
//        if(y!=0) y+=dec/cnt;
////        if(z!=0) z+=dec/cnt;
//        dfs(x,y,z,v);
//    }
    ans+=1.*c/(a+b+c);
    return mem[{a,b,c}]=ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,v;
        a=read();
        b=read();
        c=read();
        v=read();
        mem.clear();
        cout<<dfs(a,b,c,v)<<"\n";
    }
}