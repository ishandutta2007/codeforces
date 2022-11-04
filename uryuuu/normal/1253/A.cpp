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
const int maxn=100005;
 
const ll Mod=1000000007;
 
int a[maxn],b[maxn];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int pos=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                pos=i;
                k=b[i]-a[i];
                break;
            }
        }
        if(pos==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(k<=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int f=0;
//        cout<<k<<endl;
//        cout<<pos<<endl;
        while(pos<=n)
        {
            if(a[pos]+k!=b[pos])
            {
//                cout<<a[pos]<<' '<<b[pos]<<endl;

                if(a[pos]!=b[pos])
                {
//                    cout<<a[pos]<<' '<<b[pos]<<endl;
                    f=1;
                }
                break;
            }
            pos++;
        }
        while(pos<=n)
        {
            if(a[pos]!=b[pos])
                f=1;
            pos++;
        }
        if(f==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}