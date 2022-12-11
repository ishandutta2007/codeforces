#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int t,n,a[N],cl[N][N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int o=0;o<=n;o++)cl[i][o]=0;
            for(int o=i+1;o<=n;o++){
                cl[i][o]=a[i]>a[o];
                cl[i][o]+=cl[i][o-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int o=0;o<=n;o++){
                cl[i][o]+=cl[i-1][o];
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int o=i+1;o<=n;o++){
                ans+=a[i]<a[o]?cl[o-1][n]-cl[o-1][o]-cl[i][n]+cl[i][o]:0;
            }
        }
        printf("%lld\n",ans);
    }
    return  0;
}