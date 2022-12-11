#include<bits/stdc++.h>
using namespace std;
const int N=50;
int t,n,l;
struct node{
    int sum,num;
    bool operator<(const node b)const{
        return abs(sum)>abs(b.sum);
    }
}cnt[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&l);
        for(int i=1;i<=l;i++){
            cnt[i].sum=0;
            cnt[i].num=i;
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            for(int i=1;i<=l;i++){
                cnt[i].sum+=((x>>(i-1))&1)?1:-1;
            }
        }
        int ans=0;
        for(int i=1;i<=l;i++){
            if(cnt[i].sum>0)ans+=1<<(i-1);
        }
        printf("%d\n",ans);
    }
    return  0;
}