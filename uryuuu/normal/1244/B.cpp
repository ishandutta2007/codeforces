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
const int maxn=500005;
const ll Mod=1000000007;
string s;
int main()
{
    sync
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int sum=0;
        int minn=10000000,maxx=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                minn=min(i,minn);
                maxx=max(i,maxx);
                sum++;
            }
        }
        int da=n+sum;
        if(sum)
        {
            int dd=min(minn,n-1-maxx);
            da=max(da,2*(n-dd));
        }
        cout<<da<<endl;
    }
    return 0;
}