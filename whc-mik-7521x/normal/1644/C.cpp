#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],len[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]+=a[i-1];
        }
        for(int i=0;i<=n;i++)len[i]=-1e9;
        len[0]=0;
        for(int i=1;i<=n;i++){
            for(int o=1;o<=i;o++){
                len[i-o+1]=max(len[i-o+1],a[i]-a[o-1]);
            }
        }
        for(int i=n-1;i>=0;i--)len[i]=max(len[i],len[i+1]);
        int ans=-1e9;
        for(int i=0;i<=n;i++){
            ans=max(ans,len[i]+i*x);
            printf("%d ",ans);
        }
        puts("");
    }
    return  0;
}