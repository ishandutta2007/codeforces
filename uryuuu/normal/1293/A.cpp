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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005;
const ll Mod=1e9+7;

map<int,int>mp;
int main()
{
    sync;
    int n,s,k;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int aa;
        int m=0;
        cin>>n>>s>>k;
        for(int i=0;i<k;i++)
        {
            cin>>aa;
            mp[aa]++;
        }
        for(int i=0;i<1300;i++)
        {
            if(mp[s+i]==0&&s+i<=n)
            {
                m=i;
                break;
            }
            if(mp[s-i]==0&&s-i>=1)
            {
                m=i;
                break;
            }
        }
        cout<<m<<endl;;
    }
    
    return 0;
}