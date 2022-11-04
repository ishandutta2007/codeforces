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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;




int a[100];


int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        int d=10000;
        while(n)
        {
            if(d==0)
                break;
            if(n>=d)
            {
                a[cnt++]=(n/d)*d;
                n-=a[cnt-1];
            }
            d/=10;
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    
    
    
    return 0;
}