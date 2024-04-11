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
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];
int b[maxn];

int main()
{
    sync;
    int t;
    int n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int cnt=0;
        rep(i,1,n)
        {
            cin>>a[i];
            if(a[i]==k)
            {
                b[cnt++]=i;
            }
        }
//        for(int i=0;i<cnt;i++)
//            cout<<b[i]<<' ';
//        cout<<endl;
        if(n==cnt)
        {
            cout<<"yes"<<endl;
            continue;
        }
        if(cnt==0)
        {
            cout<<"no"<<endl;
            continue;
        }
        int p;
        int f=0;
        int s=0;
       
        p=b[0];
//        cout<<p<<endl;
        for(int i=p+1;i<=n;i++)
        {
            if(a[i]>=k)
            {
                s++;
            }
            else
            {
                s--;
            }
            if(s>=0)
            {
//                cout<<"Sf"<<' '<<i<<endl;
                f=1;
                break;
            }
            if(a[i]>=k)
            {
                s=0;
            }
        }
        
        s=0;
        p=b[cnt-1];
//        cout<<p<<endl;
        for(int i=p-1;i>=1;i--)
        {
            if(a[i]>=k)
            {
                s++;
            }
            else
            {
                s--;
            }
            if(s>=0)
            {
//                cout<<"SD"<<' '<<i<<endl;
                f=1;
                break;
            }
            if(a[i]>=k)
            {
                s=0;
            }
        }
        if(f)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        
    }
    
    return 0;
}