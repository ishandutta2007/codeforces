#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
const int N=1e5+10;
struct matrix{
    int h,w;
    long long mtx[2][2];
    matrix(int he=0,int we=0,long long d00=1e18,long long d01=1e18,long long d10=1e18,long long d11=1e18){
        h=he,w=we;mtx[0][0]=d00,mtx[0][1]=d01,mtx[1][0]=d10,mtx[1][1]=d11;
    }
    matrix operator*(const matrix k2)const{
        matrix res(h,k2.w);
        for(int i=0;i<h;i++){
            for(int o=0;o<k2.w;o++){
                for(int k=0;k<w;k++){
                    res.mtx[i][o]=min(mtx[i][k]+k2.mtx[k][o],res.mtx[i][o]);
                }
            }
        }
        return res;
    }
};
matrix a[N];
struct SegmentTree{
    matrix t[N<<2];
    void pushup(int rt){t[rt]=t[rt<<1]*t[rt<<1|1];}
    void build(int rt,int l,int r){
        if(l==r){t[rt]=a[l];return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    matrix query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        if(R<=mid)return query(rt<<1,l,mid,L,R);
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R);
        return query(rt<<1,l,mid,L,R)*query(rt<<1|1,mid+1,r,L,R);
    }
}tr;
int n,pos1[N],pos2[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        pos1[x]=y;
        scanf("%d%d",&x,&y);
        pos2[y]=x;
    }
    pos1[n]=pos1[n-1];
    pos2[n]=pos2[n-1];
    for(int i=1;i<n;i++){
        a[i]=matrix(2,2,abs(pos1[i]-pos1[i+1])+1,i+1-pos1[i]+i+1-pos2[i+1]+1,i+1-pos2[i]+i+1-pos1[i+1]+1,abs(pos2[i]-pos2[i+1])+1);
    }
    tr.build(1,1,n-1);
    int q;
    scanf("%d",&q);
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int s1=max(x1,y1),s2=max(x2,y2);
        if(s1>s2)swap(s1,s2),swap(x1,x2),swap(y1,y2);
        if(s1==s2){
            printf("%d\n",abs(x1-x2)+abs(y1-y2));
        }
        else if(abs(s1-s2)==1){
            matrix now=matrix(1,2,abs(s1-x1)+abs(y1-pos1[s1]),abs(s1-y1)+abs(pos2[s1]-x1));
            long long d1=now.mtx[0][0]+1,d2=now.mtx[0][1]+1;
            printf("%lld\n",min(d1+abs(s2-x2)+abs(pos1[s2-1]-y2),d2+abs(s2-y2)+abs(pos2[s2-1]-x2)));
        }
        else{
            if(s1>s2)swap(s1,s2),swap(x1,x2),swap(y1,y2);
            auto it=tr.query(1,1,n-1,s1,s2-2);
            matrix now=matrix(1,2,abs(s1-x1)+abs(y1-pos1[s1]),abs(s1-y1)+abs(pos2[s1]-x1));
            now=now*it;
            long long d1=now.mtx[0][0]+1,d2=now.mtx[0][1]+1;
            printf("%lld\n",min(d1+abs(s2-x2)+abs(pos1[s2-1]-y2),d2+abs(s2-y2)+abs(pos2[s2-1]-x2)));
        }
    }
    return  0;
}