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
#define maxn 1000100
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<9000)
        {
            cout<<'1'<<"33";
            for(int i=0;i<n;i++)
                cout<<'7';
            cout<<endl;
        }
        else
        {
            ll i=100000;
            ll sum;
            for(;i>=0;i--)
            {
                sum=1ll*i*(i-1)/2;
                if(sum<=n)
                break;
            }
            ll k=n-sum;
            cout<<'1'<<"33";
            for(int j=0;j<k;j++)
                cout<<'7';
            for(int j=0;j<i-2;j++)
                cout<<'3';
            cout<<'7'<<endl;
        }
    }
    return 0;
}