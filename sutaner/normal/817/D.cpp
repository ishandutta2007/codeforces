#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#define maxn 1000005
#define INF 2000000005
#define LL long long int
using namespace std;
LL n;
LL line[maxn];
vector<LL> save[maxn];
LL ans=0;
LL maxnum[maxn<<2];
LL minnum[maxn<<2];
void init(LL l,LL r,LL o){
    if(l==r){
        maxnum[o]=minnum[o]=line[l];
        return;
    }
    LL mid=((r-l)>>1)+l;
    init(l,mid,o<<1);
    init(mid+1,r,o<<1|1);
    maxnum[o]=max(maxnum[o<<1],maxnum[o<<1|1]);
    minnum[o]=min(minnum[o<<1],minnum[o<<1|1]);
}
LL qx,qy;
LL get_max(LL l,LL r,LL o){
    if(qx<=l&&r<=qy)return maxnum[o];
    LL mid=((r-l)>>1)+l;
    LL ans=0;
    if(qx<=mid)ans=max(ans,get_max(l,mid,o<<1));
    if(mid<qy)ans=max(ans,get_max(mid+1,r,o<<1|1));
    return ans;
}
LL get_min(LL l,LL r,LL o){
    if(qx<=l&&r<=qy)return minnum[o];
    LL mid=((r-l)>>1)+l;
    LL ans=INF;
    if(qx<=mid)ans=min(ans,get_min(l,mid,o<<1));
    if(mid<qy)ans=min(ans,get_min(mid+1,r,o<<1|1));
    return ans;
}
LL maxans=0,minans=0;
void divide_and_conquer_max(LL l,LL r){
    if(l>r)return;
    qx=l,qy=r;
    LL now=get_max(1,n,1);
    vector<LL>::iterator pos=lower_bound(save[now].begin(),save[now].end(),l);
    LL sta=0;
    vector<LL>::iterator temp=pos;
    LL pre=l;
    for(;pos!=save[now].end()&&*pos<=r;pos++){
        sta+=(*pos-pre)*(*pos-pre+1)>>1;
        pre=*pos+1;
    }
    sta+=(r-pre+1)*(r-pre+2)>>1;
    maxans+=(((r-l+1)*(r-l+2)>>1)-sta)*now;
    pre=l;
    for(;temp!=save[now].end()&&*temp<=r;temp++){
        divide_and_conquer_max(pre,*temp-1);
        pre=*temp+1;
    }
    divide_and_conquer_max(pre,r);
}
void divide_and_conquer_min(LL l,LL r){
    if(l>r)return;
    qx=l,qy=r;
    LL now=get_min(1,n,1);
    vector<LL>::iterator pos=lower_bound(save[now].begin(),save[now].end(),l);
    LL sta=0;
    vector<LL>::iterator temp=pos;
    LL pre=l;
    for(;pos!=save[now].end()&&*pos<=r;pos++){
        sta+=(*pos-pre)*(*pos-pre+1)>>1;
        pre=*pos+1;
    }
    sta+=(r-pre+1)*(r-pre+2)>>1;
    minans+=(((r-l+1)*(r-l+2)>>1)-sta)*now;
    pre=l;
    for(;temp!=save[now].end()&&*temp<=r;temp++){
        divide_and_conquer_min(pre,*temp-1);
        pre=*temp+1;
    }
    divide_and_conquer_min(pre,r);
}
void work(){
    divide_and_conquer_max(1,n);
    divide_and_conquer_min(1,n);
    printf("%I64d",maxans-minans);
}
int main(){
    /*freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);*/
    scanf("%I64d",&n);
    for(LL i=1;i<=n;i++){
        scanf("%I64d",&line[i]);
        save[line[i]].push_back(i);
    }
    init(1,n,1);
    work();
    return 0;
}