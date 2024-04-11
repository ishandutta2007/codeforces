#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,p;ll k;
int tr(int x,int p){
    int e=0;
    for(int i=0;i<p;i++) e=(e<<1)|((x>>i)&1);
    return e;
}


int main(){
    scanf("%d%lld",&n,&k);p=(n>>1);
    int bas=0;ll sum=0;k+=1;
    for(int i=0;i<(1<<(p-1));i++){
        sum=(1<<(p-1))-i;
        sum*=2ll;if(n%2) sum*=2ll,sum-=1;
        if(k>sum) k-=sum;
        else{
            bas=i;
            break;
        }
        if(i==(1<<(p-1))-1){
            printf("-1\n");
            return 0;
        }
    }
    int flag=0;
    if(n&1){
        if(k>(sum+1)/2){k-=((sum+1)/2);flag=1;}
    }
    for(int i=0;i<(1<<p);i++){
        int wt=i;
        if(i&1) wt=((1<<p)-1)^i;
        wt=tr(wt,p);
        if(wt==bas&&flag&&(i&1)){continue;}
        if(wt>=bas) k--;
        if(!k){
            for(int j=p-1;j>=0;j--) printf("%d",((bas>>j)&1));
            if(n&1){
                if(!flag) printf("0");
                else printf("1");
            }
            for(int j=p-1;j>=0;j--) printf("%d",((i>>j)&1));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}