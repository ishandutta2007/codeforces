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
const int maxn=500005;
const ll Mod=1e9+7;


int main()
{
    sync;
    int f;
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,c;
        f=0;
        cin>>n>>a>>b;
        for(int i=0;i<a;i++)
        {
            cin>>c;
            if(c==n)
                f=1;
        }
        for(int i=0;i<b;i++)
            cin>>c;
        if(f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}