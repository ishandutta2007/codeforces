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
int a[205];
int main()
{
    sync
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int id;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
                id=i;
        }
        int f=0;
        for(int i=id+1;i<n;i++)
        {
            if(a[i]-a[i-1]!=1)
            {
                f=1;
                break;
            }
        }
        for(int i=0;i<id-1;i++)
        {
            if(a[i+1]-a[i]!=1)
            {
                f=1;
                break;
            }
        }
        int ff=0;
        for(int i=id+1;i<n-1;i++)
        {
            if(a[i]-a[i+1]!=1)
            {
                ff=1;
//                cout<<"FUCK";
//                cout<<id;
                break;
            }
        }
        for(int i=0;i<=id-1;i++)
        {
            if(a[i]-a[i+1]!=1)
            {
                ff=1;
//                cout<<"FUCK";
                break;
            }
        }
        if(ff&&f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}