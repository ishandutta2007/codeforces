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
#include<unordered_map>
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
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];


int main()
{
    sync;
    int t;
    ll n,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        if(l==r&&l==1ll*n*(n-1)+1ll)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        ll s=(ll)(sqrt(1ll*(n-1)*n-l));
        s=n-s;
        ll pre;
        ll id;
        ll len;
        ll st;
        ll ss;
        id=n;
        st=1;
        for(ll i=max(min(1ll*n-1,s-500),1ll);i<=min(1ll*n-1ll,max(1ll,s+500));i++)
        {
            ss=1ll*(2ll*n*i-1ll*(i+1)*i);
            if(ss>=l)
            {
                pre=1ll*(2ll*n*(i-1)-1ll*(i-1)*i);
                id=i;
                st=l-pre;
                break;
            }
        }
        ll sum=min(r,n*(n-1))-l+1;
        len=(n-id)*2;
        for(int i=1;i<=len;i++)
        {
            if(i%2)
            {
                a[i]=id;
            }
            else
                a[i]=(i)/2+id;
        }
        int d=0;
//        cout<<st<<' '<<l<<' '<<pre<<endl;
        for(int i=st;i<=len;i++)
        {
            if(d==sum)
                break;
            cout<<a[i]<<' ';
            d++;
            if(d==sum)
              break;
        }
        while(1)
        {
            if(d==sum)
                break;
            id++;
            len-=2;
            if(len<=0)
                break;
            for(int i=1;i<=len;i++)
            {
                if(i%2)
                {
                    a[i]=id;
                }
                else
                    a[i]=(i)/2+id;
                cout<<a[i]<<' ';
                d++;
                if(d==sum)
                break;
            }
            if(d==sum)
                break;
        }
        if(r==1ll*(n-1)*n+1ll)
            cout<<1;
        cout<<endl;
    }
    return 0;
}
//1 2 1 3 2 3 1 4 2 4 3 4 1