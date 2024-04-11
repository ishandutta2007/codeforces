#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ld px,py,vx,vy,a,b,c,d;
    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    ld len=sqrt(vx*vx+vy*vy);
    cout<<fixed<<setprecision(20);

    cout<<px+vx*b/len<<" ";
    cout<<py+vy*b/len<<"\n";

    cout<<px-vy*a/2/len<<" ";
    cout<<py+vx*a/2/len<<"\n";

    cout<<px-vy*c/2/len<<" ";
    cout<<py+vx*c/2/len<<"\n";

    cout<<px-vy*c/2/len-vx*d/len<<" ";
    cout<<py+vx*c/2/len-vy*d/len<<"\n";

    cout<<px+vy*c/2/len-vx*d/len<<" ";
    cout<<py-vx*c/2/len-vy*d/len<<"\n";

    cout<<px+vy*c/2/len<<" ";
    cout<<py-vx*c/2/len<<"\n";

    cout<<px+vy*a/2/len<<" ";
    cout<<py-vx*a/2/len<<"\n";
}