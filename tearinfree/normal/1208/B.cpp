#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

int n,arr[2020],vis[2020];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);

    vector<int> ta;
    for(int i=1;i<=n;i++) ta.push_back(arr[i]);
    sort(ta.begin(),ta.end());
    ta.erase(unique(ta.begin(),ta.end()),ta.end());
    for(int i=1;i<=n;i++) arr[i]=lower_bound(ta.begin(),ta.end(),arr[i])-ta.begin();
    
    int ans=n;
    for(int i=0;i<=n;i++) {
        memset(vis,0,sizeof(vis));
        int f=1;
        for(int j=1;j<=i;j++) {
            if(vis[arr[j]]) {
                f=0;
                break;
            }
            vis[arr[j]]=1;
        }
        if(!f) break;

        int k=n;
        while(k>i && !vis[arr[k]]) vis[arr[k--]]=1;
        ans=min(ans,k-i);
    }
    printf("%d\n",ans);
    
    return 0;
}