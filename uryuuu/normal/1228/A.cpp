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

int a[20],b;
int main()
{
    sync
    int l,r;
    cin>>l>>r;
    int s=0,flag=0;
    for(int i=l;i<=r;i++)
    {
        flag=0;
        b=i;
        mm(a);
        s=0;
        while(b)
        {
            a[b%10]++;
            if(a[b%10]>1)
            {
                flag=1;
                break;
            }
            b/=10;
        }
        if(flag==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    
    cout<<-1<<endl;
    return 0;
}