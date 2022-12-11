#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=4e18;

int n,m;
int a[N],w[N],R[N];

int p[N];
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++) scanf("%d",w+i);
}
bool comp(int x,int y){
    return R[x]<R[y];
}
bool check(int mid){
    memset(R,0,sizeof(R));
    for(int i=1;i<=mid;i++) R[a[i]]=i;
    if (count(R+1,R+m+1,0)) return 0;
    for(int i=1;i<=m;i++) p[i]=i;
    sort(p+1,p+m+1,comp);
    int add=0;
    R[0]=0;
    for(int i=1;i<=m;i++){
        add+=R[p[i]]-R[p[i-1]]-1;
        if (add<w[p[i]]) return 0;
        add-=w[p[i]];
    }
    return 1;
}
int solve(){
    int L=1,R=n;
    while (L<=R){
        int mid=(L+R)/2;
        if (!check(mid)) L=mid+1;
        else R=mid-1;
    }
    if (L>n) return -1;
    return L;
}
int main(){
    prepare();
    cout<<solve();
}