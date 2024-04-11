#include <bits/stdc++.h>
using namespace std;
const int N=5050;
int n,H,W,dp[N],p[N];
tuple<int,int,int> a[N];
bool was[N];
int main(){
    scanf("%i%i%i",&n,&H,&W);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%i%i",&x,&y);
        a[i]={x,y,i};
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        int h=get<0>(a[i]),w=get<1>(a[i]),id=get<2>(a[i]);
        if(h<=H||w<=W)continue;
        dp[i]=1,p[i]=i;
        for(int j=1;j<i;j++){
            if(h>get<0>(a[j])&&w>get<1>(a[j])){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    p[i]=j;
                }
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%i\n",ans);
    if(ans==0)return 0;
    int st=0;
    for(int i=1;i<=n;i++)if(dp[i]==ans)st=i;
    vector<int> ret;
    do{
        ret.push_back(get<2>(a[st]));
        was[st]=1,st=p[st];
    }while(!was[st]);
    reverse(ret.begin(),ret.end());
    for(int c:ret)printf("%i ",c);
    return 0;
}