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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

ll c[200];

ll a[maxn],s[maxn];
int main()
{
    sync;
    int n;
    ll m;
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    cout<<0<<' ';
    c[a[1]]++;
    for(int i=2;i<=n;i++)
    {
        ll sum=0;
        if(s[i]<=m)
        {
            cout<<0<<' ';
            c[a[i]]++;
            continue;
        }
        ll d=s[i]-m;
        int pos=100;
        ll ss;
        while(pos>=1)
        {
            if(c[pos]*pos>=d)
            {
                ss=d/pos;
                if(d%pos)
                    ss++;
                sum+=ss;
                break;
            }
            else
            {
                d-=c[pos]*pos;
                sum+=c[pos];
                pos--;
            }
        }
        cout<<sum<<' ';
        c[a[i]]++;
    }
    cout<<endl;
    return 0;
}