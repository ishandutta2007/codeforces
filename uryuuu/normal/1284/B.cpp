//#include <bits/stdc++.h>
#include<iostream>
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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll  Mod=998244353;

int a[maxn],b[maxn];


int main()
{
    sync;
    int n;
    cin>>n;
    int m,d;
    int pos=0;
    ll s=0;
    int f=0;
    for(int i=0;i<n;i++)
    {
        a[pos]=99999999;
        b[pos]=-99;
        f=0;
        cin>>m;
        while(m--)
        {
            cin>>d;
            if(d>a[pos])
                f=1;
            a[pos]=min(a[pos],d);
            b[pos]=max(b[pos],d);
        }
        if(f==1)
            s++;
        else
            pos++;
    }
    
    sort(a,a+pos);
    ll sum=0;
    for(int i=0;i<pos;i++)
    {
        sum+=ll(lower_bound(a,a+pos,b[i])-a);
    }
//    cout<<s<<' '<<n<<endl;
    cout<<sum+1ll*s*n*2-1ll*s*s<<endl;
    return 0;
}