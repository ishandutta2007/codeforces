#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
 
const ll Mod=1000000007;

ll a[maxn],s[maxn],ss[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(i>m)
            ss[i]=a[i]+ss[i-m];
        else
            ss[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i>m)
        {
//            cout<<i<<endl;
//            cout<<a[i]<<' ';
//            sum+=(a[i]+a[i-m]);
//            cout<<sum+(s[i]-s[((i-1)/m)*m])+s[i-m]<<' '<<endl;
//            cout<<s[((i-1)/m)*m]<<' '<<s[i]<<' '<<' '<<sum<<' '<<(s[i]-s[((i-1)/m)*m])<<' '<<s[i-m]<<' '<<endl;
//            cout<<a[i]<<' '<<s[i]-s[(i/m)*m]+sum+(s[i-m]-s[(i/m)*m-m])<<endl;
            sum+=ss[i];
            cout<<sum<<' ';
        }
        else
        {
//            sum+=(a[i]);
//            cout<<a[i]<<' ';
            sum+=ss[i];
            cout<<s[i]<<' ';
//            cout<<s[i]<<' '<<endl;
        }
//        if(i%m==0)
//        {
//            sum+=s[i];
//        }
////            cout<<endl<<sum<<endl;
//        }
    }
    cout<<endl;
    return 0;
}