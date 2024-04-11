#include <bits/stdc++.h>
using namespace std;
const int N=35050;
const int M=2*N;
const int inf=1e9;
int a[N],root,tsz,ls[M],rs[M],st[M],lzy[M],lst[N],pos[N];
int dp[N],new_dp[N];
void Build(int&c,int ss,int se){
    if(!c)c=++tsz;
    st[c]=lzy[c]=0;
    if(ss==se)return;
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
}
void Push(int c,bool l){
    st[c]+=lzy[c];
    if(!l){lzy[c]=0;return;}
    lzy[ls[c]]+=lzy[c];
    lzy[rs[c]]+=lzy[c];
    lzy[c]=0;
}
void Set(int c,int ss,int se,int qs,int qe,int val){
    Push(c,ss!=se);
    if(ss>se||se<qs||ss>qe)return;
    if(qs<=ss&&se<=qe){
        lzy[c]+=val;
        Push(c,ss!=se);
        return;
    }
    int mid=ss+se>>1;
    Set(ls[c],ss,mid,qs,qe,val);
    Set(rs[c],mid+1,se,qs,qe,val);
    st[c]=min(st[ls[c]],st[rs[c]]);
}
int Get(int c,int ss,int se,int qs,int qe){
    if(ss>se||se<qs||ss>qe)return inf;
    Push(c,ss!=se);
    if(qs<=ss&&se<=qe)return st[c];
    int mid=ss+se>>1;
    return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main(){
    int n,k;scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++){
        pos[i]=lst[a[i]],lst[a[i]]=i,dp[i]+=dp[i-1];
        if(pos[i])dp[i]+=i-pos[i];
    }
    for(int j=1;j<k;j++){
        Build(root,0,n);
        Set(root,0,n,0,0,inf);
        for(int i=1;i<=n;i++){
            if(pos[i])Set(root,0,n,0,pos[i]-1,i-pos[i]);
            new_dp[i]=Get(root,0,n,0,i-1);
            Set(root,0,n,i,i,dp[i]);
        }
        for(int i=1;i<=n;i++)dp[i]=new_dp[i];
    }
    printf("%i",dp[n]);
    return 0;
}