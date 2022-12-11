#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t,a[N],n;
pair<int,int>ch[N];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&ch[i].first,&ch[i].second);
        }
        sort(ch+1,ch+n+1,[](pair<int,int>b1,pair<int,int>b2){return b1.second-b1.first<b2.second-b2.first;});
        for(int i=1;i<=n;i++){
            printf("%d %d ",ch[i].first,ch[i].second);
            for(int o=ch[i].first;o<=ch[i].second;o++){
                if(!a[o]){
                    printf("%d\n",o);
                    a[o]=1;
                }
            }
        }
        puts("");
    }
    return  0;
}