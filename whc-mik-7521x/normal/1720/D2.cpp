#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int trie[N<<5][2],val[N<<5][2],ct,rt,t,n,a[N];
int ins(int &x,int vl,int num,int ad,int mx){
    if(!x)x=++ct;
    // cout<<x<<' '<<vl<<' '<<num<<' '<<ad<<' '<<mx<<endl;
    if(!ad){
        val[x][!!((vl^num)&1)]=max(mx,val[x][!!((vl^num)&1)]);
        return mx;
    }
    int to=!!(vl&ad);
    mx=max(mx,val[trie[x][!to]][(!!(num&(ad)))]+1);
    int res=ins(trie[x][to],vl,num,ad>>1,mx);
    return val[x][!!((vl^num)&(ad<<1))]=max(val[x][!!((vl^num)&(ad<<1))],res),res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=ct;i++)trie[i][0]=trie[i][1]=val[i][0]=val[i][1]=0;
        ct=rt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,ins(rt,a[i]^i,i,1<<30,1));
        }
        printf("%d\n",ans);
    }
    return 0;
}