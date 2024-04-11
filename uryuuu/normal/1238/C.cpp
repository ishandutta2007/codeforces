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

int a[200005];
int main()
{
    sync;
    int t;
    cin>>t;
    int h,n,s,d,dd,ddd;
    while(t--)
    {
        cin>>h>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        s=0;
        int sum=0;
        while(s<n-1)
        {
            d=a[s]-a[s+1];
            if(d==1)
            {
                if(s+2<n)
                {
                    dd=a[s]-a[s+2];
                    if(dd==2)
                    {
                        
                        s=s+2;
                        continue;
                    }
                    else
                    {
                        sum++;
                        s++;
                        a[s]=a[s+1]+1;
                        continue;
                    }
                }
                else
                    break;
            }
            else
            {
                a[s]=a[s+1]+1;
                continue;
            }
        }
//        cout<<a[s]<<' '<<sum<<' ';
        if(s!=n-1)
            if(a[s]>2)
                sum++;
        cout<<sum<<endl;
    }
    return 0;
}