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


ll a[20005];
int v[200];
int b[200];

int main()
{
    sync;
    int t;
    int n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        mm(v);
        rep(i,1,n)
        {
            cin>>a[i];
            v[a[i]]++;
        }
        int cnt=0;
        for(int i=1;i<=100;i++)
        {
            if(v[i])
            {
                b[cnt++]=i;
            }
        }
        if(cnt>k)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=100;i++)
        {
            if(cnt>=k)
                break;
            if(v[i]==0)
            {
                b[cnt++]=i;
            }
            if(cnt>=k)
                break;
        }
        
        
        cout<<n*cnt<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                cout<<b[j]<<' ';
            }
        }
        cout<<endl;
    }
    
    
    return 0;
}