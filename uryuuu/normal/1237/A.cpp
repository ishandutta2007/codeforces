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
int a[200005];
int main()
{
    sync
    int s=0,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2)
            s++;
    }
    s/=2;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            cout<<a[i]/2<<endl;
        else
        {
            if(s>0)
            {
                if(a[i]<0)
                    cout<<a[i]/2-1<<endl;
                else
                    cout<<a[i]/2<<endl;
            }
            else
            {
                if(a[i]<0)
                    cout<<a[i]/2<<endl;
                else
                    cout<<a[i]/2+1<<endl;
            }
            s--;
        }
    }
    return 0;
}