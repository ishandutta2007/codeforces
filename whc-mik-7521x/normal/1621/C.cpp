#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ans[N],pd[N];
        for(int i=1;i<=n;i++)pd[i]=0;
        for(int i=1;i<=n;i++){
            if(!pd[i]){
                int now;
                vector<int>v;
                printf("? %d\n",i);
                fflush(stdout);
                scanf("%d",&now);
                while(!v.size()||v.back()!=now){
                    printf("? %d\n",i);
                    fflush(stdout);
                    int kk;
                    scanf("%d",&kk);
                    v.push_back(kk);
                }
                for(int i=0;i<(int)v.size()-1;i++){
                    ans[v[i]]=v[i+1];
                    pd[v[i]]=1;
                }
                ans[now]=v[0];
                pd[now]=1;
            }
        }
        putchar('!');
        for(int i=1;i<=n;i++)printf(" %d",ans[i]);
        puts("");
        fflush(stdout);
    }
    return  0;
}