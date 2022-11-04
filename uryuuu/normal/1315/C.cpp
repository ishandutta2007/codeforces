#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;


int a[300],b[300],v[300];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mm(v);
        mm(a);
        int n;
        cin>>n;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            if(v[b[i]])
                f=1;
            v[b[i]]=1;
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            a[2*i-1]=b[i];
            for(int j=b[i]+1;j<=2*n;j++)
            {
                if(v[j]==0)
                {
                    a[2*i]=j;
                    v[j]=1;
                    break;
                }
            }
            if(a[2*i]==0)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=2*n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}