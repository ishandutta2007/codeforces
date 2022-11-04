#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;

ll q1,e1,q2,e2;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        cin>>n;
        q1=q2=e1=e2=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x%2)
                q1++;
            else
                e1++;
        }
        cin>>m;
        for(int i=0;i<m;i++)
       {
           cin>>x;
           if(x%2)
               q2++;
           else
               e2++;
       }
        ll s=0;
        if(e2)
        {
            s+=(e2*e1);
        }
        if(q2)
        {
            s+=(q1*q2);
        }
        cout<<s<<endl;
    }
    
    return 0;
}