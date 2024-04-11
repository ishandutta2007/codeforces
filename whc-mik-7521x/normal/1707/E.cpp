#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n,q,lg[N];
template<typename T>inline void read(T &t){
    bool flag=1;
    char c=getchar();t=0;
    while(!isdigit(c)){
        if(c=='-')flag=0;
        c=getchar();
    }
    while(isdigit(c))t=(t<<3)+(t<<1)+c-48,c=getchar();
    if(!flag)t=~(t-1);
}
template<typename T,typename...Args>inline void read(T &t,Args &...args){read(t);read(args...);}
template<typename T> inline void wrt(T x)
{
    short st[105],tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
}
struct node{
    int l,r;
    node(int L=1e9,int R=0){l=L,r=R;}
    node operator+(const node b)const{
        return node(min(l,b.l),max(r,b.r));
    }
    bool operator!=(const node b)const{
        return l!=b.l||r!=b.r;
    }
    void print(){cout<<l<<' '<<r<<endl;}
}st[20][40][N];
node query(node now,int stp){
    int kk=lg[now.r-now.l];
    return st[kk][stp][now.l]+st[kk][stp][now.r-(1<<kk)];
}
long long ask(node now){
    long long ans=0;
    if(!(now!=node(1,n)))return 0;
    if(now.r==now.l)return n==1?0:-1ll;
    if(query(now,34)!=node(1,n))return -1ll;
    for(int i=34;i>=0;i--){
        if(query(now,i)!=node(1,n))now=query(now,i),ans+=1ll<<i;
    }
    return ans+1;
}
int main(){
    for(int i=2;i<N;i++)lg[i]=lg[i>>1]+1;
    read(n,q);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    for(int i=1;i<n;i++)st[0][0][i]=node(min(a[i],a[i+1]),max(a[i],a[i+1]));
    // if(n==100000)return puts("?"),0;
    for(int k=0;k<35;k++){
        if(k)for(int i=1;i<n;i++)st[0][k][i]=query(st[0][k-1][i],k-1);
        for(int o=1;o<17;o++){
            for(int i=1;i+(1<<o)<=n;i++){
                st[o][k][i]=st[o-1][k][i]+st[o-1][k][i+(1<<(o-1))];
            }
        }
    }
    while(q--){
        int l,r;
        read(l,r);
        printf("%lld\n",ask(node(l,r)));
    }
    return 0;
}