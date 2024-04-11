#include<bits/stdc++.h>
using namespace std;
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
const int N = 2e5+9;

int n,m;
struct sec{
    int l,r,id;
    void in(){scanf("%d%d",&l,&r);}
    int len(){return (r-l+1);}
}a[N],b[N];
bool cmp(sec x,sec y){return x.len()<y.len();}

struct pp{int ch[2],mn;}t[N<<5];
int Min(int x,int y){if(!x) return y;if(!y) return x;return min(x,y);}
int rt[N],cnt;
int Nw(){return ++cnt;}
void modi(int &c,int l,int r,int x,int val){
    if(!c) c=Nw();if(l==r){t[c].mn=Min(val,t[c].mn);return ;}
    int mid=(l+r)>>1;if(x<=mid) modi(ls(c),l,mid,x,val);if(x>mid) modi(rs(c),mid+1,r,x,val);
    t[c].mn=min(t[ls(c)].mn,t[rs(c)].mn);return ;
}
int que(int c,int l,int r,int x,int y){
    if(!c||(x<=l&&r<=y)) return t[c].mn;
    int mid=(l+r)>>1,ans=N;if(x<=mid) ans=min(ans,que(ls(c),l,mid,x,y));if(y>mid) ans=min(ans,que(rs(c),mid+1,r,x,y));
    return ans;
}

int lowbit(int x){return x&(-x);}
void ins(int l,int r,int id){while(r<=n){modi(rt[r],1,n,l,id);r+=lowbit(r);}return ;}
int ask(int l,int r){int ans=N;while(r>=l){ans=min(ans,que(rt[r],1,n,l,n));r-=lowbit(r);}return ans;}

int calc(int l,int r){
    if(l>r) return 0;
    int c=ask(l,r);
    if(c>m||c<1) return 0; 
    return b[c].r-b[c].l+1+calc(l,b[c].l-1)+calc(b[c].r+1,r);
}

int ans[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){a[i].in();a[i].id=i;b[i]=a[i];}
    sort(a+1,a+m+1,cmp);
    t[0].mn=N;int j=m;
    for(int i=n;i>=1;i--){
        while(j&&a[j].len()>=i){ins(a[j].l,a[j].r,a[j].id);j--;}
        ans[i]=calc(1,n);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}