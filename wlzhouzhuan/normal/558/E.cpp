#include<bits/stdc++.h>
using namespace std;

const int N=200005;

char a[N];
int n,m;

#define ls (u<<1)
#define rs (u<<1|1)
struct node{
  int cnt[26],lzy;
}seg[N<<2];
node merge(node a,node b){
  node ans;
  ans.lzy=-1;
  for(int i=0;i<26;i++){
    ans.cnt[i]=a.cnt[i]+b.cnt[i];
  }
  return ans;
}
void pushdown(int u,int l,int r){
  if(seg[u].lzy!=-1){
    int mid=l+r>>1;
    for(int i=0;i<26;i++)seg[ls].cnt[i]=seg[rs].cnt[i]=0;
    seg[ls].lzy=seg[rs].lzy=seg[u].lzy;
    seg[ls].cnt[seg[u].lzy]=mid-l+1;
    seg[rs].cnt[seg[u].lzy]=r-mid;
    seg[u].lzy=-1;
  }
}
void build(int u,int l,int r){
  seg[u].lzy=-1;
  if(l==r){
    seg[u].cnt[a[l]-'a']++;
    return;
  }
  int mid=l+r>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
  seg[u]=merge(seg[ls],seg[rs]);
}
void fix(int u,int l,int r,int ql,int qr,int x){
  pushdown(u,l,r);
  if(ql<=l&&r<=qr){
    //printf("fix %d %d %d %d %d %d\n",u,l,r,ql,qr,x);
    for(int i=0;i<26;i++)seg[u].cnt[i]=0;
    seg[u].lzy=x;
    seg[u].cnt[x]=r-l+1;
    return;
  }
  pushdown(u,l,r);
  int mid=l+r>>1;
  if(ql<=mid)fix(ls,l,mid,ql,qr,x);
  if(qr>mid)fix(rs,mid+1,r,ql,qr,x);
  seg[u]=merge(seg[ls],seg[rs]);
}
node query(int u,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return seg[u];
  pushdown(u,l,r);
  int mid=l+r>>1;
  if(qr<=mid)return query(ls,l,mid,ql,qr);
  if(ql>mid)return query(rs,mid+1,r,ql,qr);
  return merge(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
void print(int u,int l,int r){
  if(l==r){
    int let=0;
    for(int i=0;i<26;i++){
      if(seg[u].cnt[i])let=i;
    }
    printf("%c",char(let+'a'));
    return;
  }
  pushdown(u,l,r);
  int mid=l+r>>1;
  print(ls,l,mid);
  print(rs,mid+1,r);
}
int main(){
  //freopen("1.in","r",stdin);
  //freopen("1.out","w",stdout); 
  scanf("%d%d",&n,&m);
  scanf("%s",a+1);
  build(1,1,n);
  //print(1,1,n);
  while(m--){
    int l,r,opt;
    scanf("%d%d%d",&l,&r,&opt);
    if(l>r)swap(l,r);
    node t=query(1,1,n,l,r);
    if(opt){
      int cur=l;
      for(int i=0;i<26;i++){
        //printf("i=%d, cnt=%d\n",i,t.cnt[i]); 
        if(t.cnt[i])
          fix(1,1,n,cur,cur+t.cnt[i]-1,i);
        cur+=t.cnt[i];
      }
    }else{
      int cur=l;
      for(int i=25;i>=0;i--){
        if(t.cnt[i])
          fix(1,1,n,cur,cur+t.cnt[i]-1,i);
        cur+=t.cnt[i];
      }
    }
    //print(1,1,n);
    //putchar('\n');
  }
  print(1,1,n);
  return 0; 
}