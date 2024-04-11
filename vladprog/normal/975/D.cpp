#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

#define y0 erobijerbi0
#define y1 erobijerbi1
#define y2 erobijerbi2

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin>>n>>a>>b;
    map<array<int,3>,vector<array<int,3>>> m;
    while(n--)
    {
        int x1,vx,vy;
        cin>>x1>>vx>>vy;
        int y1=a*x1+b,z1=0;
        int x2=x1+vx,y2=y1+vy,z2=1;
        int x3=x1+1,y3=a*x3+b,z3=0;
        int A=(y2-y1)*(z3-z1)-(z2-z1)*(y3-y1);
        int B=(z2-z1)*(x3-x1)-(x2-x1)*(z3-z1);
        int C=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
        int g=__gcd(A,__gcd(B,C));
        A/=g,B/=g,C/=g;
        #define inv A=-A,B=-B,C=-C
        if(A<0) inv;
        else if(A==0)
            if(B<0) inv;
            else if(B==0)
                if(C<0) inv;
        m[{A,B,C}].push_back({x1,vx,vy});
    }
    int ans=0;
    for(auto p:m)
    {
        auto v=p.second;
        map<array<int,2>,int> m1;
        for(auto line:v)
            m1[{line[1],line[2]}]++;
        ans+=int(v.size())*v.size();
        for(auto cur:m1)
            ans-=cur.second*cur.second;
    }
    cout<<ans;
}