#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,t,SG[N],vis[N];
char c[N];
int main(){
    for(int i=1;i<=1000;++i){
        for(int o=0;o<=i-2;++o)vis[SG[o]^SG[i-2-o]]=1;
        int o=0;
        while(vis[o])o++;
        SG[i]=o;
        for(int o=0;o<=i-2;++o)vis[SG[o]^SG[i-2-o]]=0;
    }
    for(int i=1001;i<N;++i)SG[i]=SG[i-34];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",c+1);
        int s=0;
        for(int i=1;i<=n;++i)s+=c[i]=='R'?1:-1;
        if(s>0)puts("Alice");
        if(s<0)puts("Bob");
        if(s==0){
            int ans=0;
            for(int i=1;i<=n;){
                int o=i+1;
                while(o<=n&&c[o]!=c[o-1])o++;
                ans^=SG[o-i];
                i=o;
            }
            puts(ans?"Alice":"Bob");
        }
    }
}