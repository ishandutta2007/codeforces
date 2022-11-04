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
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=998244353;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[200010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int b,w;
        scanf("%d%d",&b,&w);
        if(b==w)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=b+w;i++)
                cout<<1<<' '<<i<<endl;
        }
        else if(w>b)
        {
            if(w>3*b+1)
                cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
                int x=2;
                for(int i=1;i<=b;i++)
                    cout<<x<<' '<<1+2*i<<endl;
                for(int i=1;i<=b;i++)
                    cout<<x<<' '<<2*i<<endl;
                if(w<=2*b)
                {
                    for(int i=1;i<=w-b;i++)
                        cout<<x-1<<' '<<1+2*i<<endl;
                }
                else
                {
                    for(int i=1;i<=b;i++)
                        cout<<x-1<<' '<<1+2*i<<endl;
                }
                if(w<=3*b)
                {
                    for(int i=1;i<=w-2*b;i++)
                        cout<<x+1<<' '<<2*i+1<<endl;
                }
                else
                {
                    for(int i=1;i<=b;i++)
                        cout<<x+1<<' '<<2*i+1<<endl;
                }
                if(w==3*b+1)
                    cout<<x<<' '<<2*b+2<<endl;
            }
        }
        else
        {
            swap(w,b);
            if(w>3*b+1)
                cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
                int x=3;
                for(int i=1;i<=b;i++)
                    cout<<x<<' '<<1+2*i<<endl;
                for(int i=1;i<=b;i++)
                    cout<<x<<' '<<2*i<<endl;
                if(w<=2*b)
                {
                    for(int i=1;i<=w-b;i++)
                        cout<<x-1<<' '<<1+2*i<<endl;
                }
                else
                {
                    for(int i=1;i<=b;i++)
                        cout<<x-1<<' '<<1+2*i<<endl;
                }
                if(w<=3*b)
                {
                    for(int i=1;i<=w-2*b;i++)
                        cout<<x+1<<' '<<2*i+1<<endl;
                }
                else
                {
                    for(int i=1;i<=b;i++)
                        cout<<x+1<<' '<<2*i+1<<endl;
                }
                if(w==3*b+1)
                    cout<<x<<' '<<2*b+2<<endl;
            }
        }
    }
    return 0;
}