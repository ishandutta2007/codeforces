#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
    int a,b,c,d;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a>b)swap(a,b);
        int ans=b-a;
        int l=max(a,c-d);
        int r=min(b,c+d);
//        cout<<l<<" "<<r<<endl;
        ans-=max(0,r-l);
        cout<<ans<<endl;
    }
    return 0;
}