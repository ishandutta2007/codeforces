#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

vector<int>lst[maxn],v;
int n;
ll ans;
bool vis[maxn];

bool judge(int o)
{
    for(int i=1;i<lst[o].size();i++)
    {
        if(lst[o][i]>lst[o][i-1])
        {
            vis[o]=1;
            return 1;
        }
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    ans=(ll)n*n;
    for(int i=0;i<n;i++)
    {
        int len;
        scanf("%d",&len);
        while(len--)
        {
            int a;
            scanf("%d",&a);
            lst[i].push_back(a);
        }
        if(!judge(i))
        {
            v.push_back(lst[i][0]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)if(!vis[i])
    {
        ans-=upper_bound(v.begin(),v.end(),lst[i][lst[i].size()-1])-v.begin();
    }
    printf("%lld",ans);
    return 0;
}