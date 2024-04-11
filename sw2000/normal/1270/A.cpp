#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k1,k2;
        cin>>n>>k1>>k2;
        bool f=0;
        for(int i=0;i<k1;i++)
        {
            int a;
            cin>>a;
            if(a==n)f=1;
        }
        for(int i=0;i<k2;i++)
        {
            int a;
            cin>>a;
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}