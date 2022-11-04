#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 500010
using namespace std;
int a[505];
int main()
{
    sync
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        n*=4;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int f=0;
        int s=a[0]*a[n-1];
        int l=0,r=n-1;
        while(l<r)
        {
            if(s!=a[l]*a[r])
            {
//                cout<<l<<' '<<r<<endl;
                f=1;
                break;
            }
            if(a[l]!=a[l+1]||a[r]!=a[r-1])
            {
                //                cout<<l<<' '<<r<<endl;
                f=1;
                break;
            }
            l+=2;
            r-=2;
        }
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}