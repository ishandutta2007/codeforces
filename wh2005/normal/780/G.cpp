#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mi map<int ,int >::iterator 
#define fi first 
#define se second 
const int inf = 2147483647;
const int N = 1e6+9;
const ll mod = 1e9+7;
int h,w,n;
struct pp{int u,l,r,s;}a[N];
bool cmp(pp x,pp y){return x.u>y.u;}
struct segment{int mn;}t[N<<2];
map<int ,int >mp[N];
void pushup(int c){t[c].mn=min(t[ls(c)].mn,t[rs(c)].mn);return ;}
void build(int c,int l,int r){
    if(l==r){t[c].mn=h+1;mp[l][h+1]=1;return ;}
    int mid=(l+r)>>1;build(ls(c),l,mid);build(rs(c),mid+1,r);pushup(c);return ;
}
ll num;
void modify(int c,int l,int r,int x,int y,int d){
    if(l==r){
        mi it=mp[l].begin();
        while(it!=mp[l].end()&&(*it).fi<=d){
            (num+=(*it).se)%=mod;mp[l].erase(it);it=mp[l].begin();
        }
        if(mp[l].begin()==mp[l].end()) t[c].mn=inf;
        else t[c].mn=(*it).fi;
        return ;
    }
    int mid=(l+r)>>1;
    if(t[ls(c)].mn<=d&&x<=mid) modify(ls(c),l,mid,x,y,d);
    if(t[rs(c)].mn<=d&&y>mid) modify(rs(c),mid+1,r,x,y,d);
    pushup(c);return ;
}
void insert(int c,int l,int r,int x,int y,int z){
    if(l==r){(mp[l][y]+=z)%=mod;t[c].mn=min(t[c].mn,y);return ;}
    int mid=(l+r)>>1;
    if(x<=mid) insert(ls(c),l,mid,x,y,z);if(x>mid) insert(rs(c),mid+1,r,x,y,z);
    pushup(c);return ;
}
int main(){
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i].u,&a[i].l,&a[i].r,&a[i].s);a[i].s+=a[i].u;
    }
    build(1,1,w);
    sort(a+1,a+n+1,cmp);
    ll ans=w;
    for(int i=1;i<=n;i++){
        num=0;
        modify(1,1,w,a[i].l,a[i].r,a[i].s);
        if(a[i].l==1) insert(1,1,w,a[i].r+1,a[i].u,num*2ll%mod);
        else if(a[i].r==w) insert(1,1,w,a[i].l-1,a[i].u,num*2ll%mod);
        else{
            insert(1,1,w,a[i].l-1,a[i].u,num);
            insert(1,1,w,a[i].r+1,a[i].u,num);
        }
        (ans+=1ll*num)%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}