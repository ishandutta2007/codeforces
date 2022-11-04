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
const int maxn=200005;
const ll Mod=1000000007;


int a[maxn],q,n;
ll sum=0,num[maxn];
map<pair<int,int>,int>mp;
int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cin>>q;
    while(q--)
    {
        int l,r,w;
        cin>>l>>r>>w;
        if(!mp[make_pair(l,r)])
        {
            num[w]++;
            if(num[w]<=a[w])
                sum--;
            mp[make_pair(l,r)]=w;
        }
        else
        {
            int ls=mp[make_pair(l,r)];
            num[ls]--;
            if(num[ls]<a[ls])
                sum++;
            mp[make_pair(l,r)]=w;
            if(w)
            {
                num[w]++;
                if(num[w]<=a[w])
                    sum--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}