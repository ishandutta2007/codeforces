#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;



int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        ll d,h;
        cin>>n>>x;
        ll mx=-1,da=-1;
        for(int i=0;i<n;i++)
        {
            cin>>d>>h;
            mx=max(d,mx);
            da=max(d-h,da);
        }
        if(mx>=x)
        {
            cout<<1<<endl;
            continue;
        }
        if(da<=0)
        {
            cout<<-1<<endl;
            continue;
        }
        ll s=x-mx;
        if(s%da==0)
            s/=da;
        else
            s=s/da+1;
        cout<<s+1<<endl;
    }
    
    return 0;
}