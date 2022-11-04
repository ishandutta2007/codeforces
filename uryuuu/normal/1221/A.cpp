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
ll a[105];

int main()
{
    sync;
    int q;
    int n;
    cin>>q;
    while(q--)
    {
        mm(a);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int f=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]==2048)
            {
                f=1;
                break;
            }
            if(a[i-1]>2048)
            {
                break;
            }
            if(a[i]==a[i-1])
                a[i]=2*a[i];
            sort(a+i,a+n);
        }
        if(a[n-1]==2048)
            f=1;
        if(f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
            
    }
    
    
    return 0;
}