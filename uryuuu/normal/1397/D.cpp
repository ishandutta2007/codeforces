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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1,cmp);
        a[n+1]=0;
        int pos=0;
        int ans=0;
        while(1)
        {
            if(pos==1)
                pos=2;
            else
                pos=1;
            if(a[pos]==0)
                break;
            a[pos]--;
            for(int i=pos+1;i<=n;i++)
            {
                if(a[i]>a[pos])
                {
                    swap(a[i],a[pos]);
                    pos=i;
                }
                else
                    break;
            }
            ans++;
        }
        if(ans%2)
            cout<<"T"<<endl;
        else
            cout<<"HL"<<endl;
    }
    
    return 0;
}