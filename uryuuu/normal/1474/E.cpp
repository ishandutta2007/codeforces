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
#include<unordered_map>
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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;


int a[maxn];
vector<pii>ans;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            a[i]=i;
        int cnt=n-1;
        ll sum=0;
        for(int i=n-1;i>=1;i--)
        {
            swap(a[i+1],a[1]);
            ans.push_back(mkp(i+1,1));
            sum+=1ll*i*i;
            cnt--;
            if(cnt==0)
                break;
            if(i==n-1)
                continue;
            swap(a[n-i],a[n]);
            ans.push_back(mkp(n-i,n));
            sum+=1ll*i*i;
            cnt--;
            if(cnt==0)
                break;
        }
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
        cout<<n-1<<endl;
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i].first<<' '<<ans[i].second<<endl;
        
        
        
        
    }
    
    return 0;
}