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

int a[100005];
int main()
{
    sync;
    int t;
    cin>>t;
    int n,d,s,m,k;
    while(t--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        k=a[n-1];
        m=unique(a,a+n)-a;
        if(m==1)
        {
            cout<<1<<endl;
            continue;
        }
        int l=1,r=m,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[m-mid-1]-mid*d<=0)
                r=mid;
            else
                l=mid+1;
        }
        int f=l-1;
        if(a[m-f-1]-f*d<=0)
            cout<<l<<endl;
        else if(a[m-l-1]-l*d<=0)
            cout<<l<<endl;
        else
            cout<<l+1<<endl;
    }
    
    return 0;
}