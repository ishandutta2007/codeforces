#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,r[N],c[N],ct1[N*N],ct2[N*N];
pair<int,int>pos[N*N];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            int x;
            scanf("%d",&x);
            pos[x]={i,o};
        }
    }
    for(int i=1;i<=n*n;i++){
        ans+=1ll*(n-1-r[pos[i].first])*c[pos[i].second]+1ll*(n-1-c[pos[i].second])*r[pos[i].first];
        r[pos[i].first]++;
        c[pos[i].second]++;
    }
    printf("%lld",ans>>1);
    return  0;
}