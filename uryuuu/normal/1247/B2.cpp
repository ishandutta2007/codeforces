#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 1000006
int a[maxn];
int vis[maxn];
int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,k,d;cin>>n>>k>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=INF;
        int tmp=0;
        memset(vis,0,sizeof(int)*(k+5));
        for(int k=1;k<=d;k++){
            if(!vis[a[k]]) tmp++;
            vis[a[k]]++;
        }
        ans=tmp;
        for(int i=2,j=d+1;j<=n;j++,i++){
            vis[a[i-1]]--;
            if(vis[a[i-1]]==0){
                tmp--;
            }
            if(vis[a[j]]==0){
                tmp++;
            }
            vis[a[j]]++;
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
    }
#ifndef ONLINE_JUDGE
    cout<<endl;system("pause");
#endif
    return 0;
}