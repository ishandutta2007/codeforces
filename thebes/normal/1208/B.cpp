#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 2005;
map<int,int> mp;
int n, i, j, arr[MN], cnt[MN], c, f, g[MN], ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]), mp[arr[i]]=0;
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++i;
    for(i=1;i<=n;i++){
        arr[i] = mp[arr[i]];
        cnt[arr[i]]++;
        if(cnt[arr[i]]==1) c++;
    }
    if(c==n) ans = 0;
    else ans = 1<<30;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) g[j]=cnt[j];
        f = c;
        for(j=i;j<=n;j++){
            g[arr[j]]--;
            if(g[arr[j]]>=1) f++;
            if(f==n){
                ans = min(ans,j-i+1);
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}