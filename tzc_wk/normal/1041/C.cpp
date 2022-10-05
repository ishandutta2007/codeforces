#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,d,q[N],ans[N],tot=0,hd,tl;
struct Node{int v,id;}a[N];
inline bool cmp(Node a,Node b){return a.v<b.v;}
int main(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;++i)cin>>a[i].v,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    hd=1,tl=0;
    q[++tl]=1,ans[a[1].id]=++tot;
    for(int i=2;i<=n;++i){
        if(a[i].v-d-1>=a[q[hd]].v)ans[a[i].id]=ans[a[q[hd]].id],++hd;
        else ans[a[i].id]=++tot;
        q[++tl]=i;
    }
    cout<<tot<<endl;
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
    return 0;
}