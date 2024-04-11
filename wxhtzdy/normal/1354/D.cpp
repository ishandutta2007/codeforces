#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int a[N],bit[N];
void Add(int x,int val){for(;x<N;x+=x&(-x))bit[x]+=val;}
int Get(int x){int res=0;for(;x>0;x-=x&(-x))res+=bit[x];return res;}
int Find(int k){
    int bot=1,top=N,ans=0;
    while(bot<=top){
        int mid=bot+top>>1;
        if(Get(mid)<k)ans=mid,bot=mid+1;
        else top=mid-1;
    }
    return ans+1;
}
int main(){
    int n,q;scanf("%i %i",&n,&q);
    for(int i=0,a;i<n;i++)scanf("%i",&a),Add(a,1);
    //printf("%i\n",Find(4));
    for(int i=0;i<q;i++){
        int k;scanf("%i",&k);
        //if(k<0)printf("%i\n",Find(abs(k)));
        if(k>0)Add(k,1);
        else Add(Find(abs(k)),-1);
    }
    //printf("%i",Get(N-1));
    if(Get(N-1)==0)printf("0");
    else printf("%i",Find(1));
    return 0;
}