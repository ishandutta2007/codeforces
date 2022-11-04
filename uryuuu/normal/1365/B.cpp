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
//#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[600],b[600];


int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int f1=0,f2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            if(b[i]==1)
                f1++;
            else
                f2++;
        }
        if(f1&&f2)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else
        {
            int f=0;
            for(int i=2;i<=n;i++)
            {
                if(a[i]<a[i-1])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    
    return 0;
}