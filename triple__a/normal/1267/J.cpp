#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2000007;
int t,n;
int vec[maxn];

int ck(int u,int j){
    int ans=0;
    for (int i=u;i<=n;++i){
        int tmp=vec[i]%j;
        if (tmp) tmp=j-tmp;
        if (tmp*(j-1)>vec[i]) return -1;
        ans+=tmp+(vec[i]-(j-1)*tmp)/j;
    }
    return ans;
}

#undef int
int main(){
    scanf("%lld",&t);
    while (t--){
        scanf("%lld",&n);
        for (int i=1;i<=n;++i){
            vec[i]=0;
        }
        for (int i=1;i<=n;++i){
            int u;
            scanf("%d",&u);
            vec[u]++;
        }
        sort(vec+1,vec+n+1);
        int mn,idx;
        for (int i=1;i<=n;++i){
            if (vec[i]){
                mn=vec[i];
                idx=i;
                break;
            }
        }
        int ans=100000007;
        for (int i=2;i<=mn+1;++i){
            int sum=ck(idx,i);
//            printf("%d %d %d\n",idx,i,sum);
            if (sum!=-1) ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}