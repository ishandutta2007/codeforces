#include <bits/stdc++.h>
using namespace std;

const int N=300050;
const int M=20*N;

int a[N],need;
int root[N],ls[M],rs[M],st[M],tsz;
void Set(int p,int&c,int ss,int se,int qi){
    c=++tsz;ls[c]=ls[p];rs[c]=rs[p];st[c]=st[p]+1;
    if(ss==se)return;
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
    else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p,int c,int ss,int se){
    if(st[c]-st[p]<=need)return -1;
    if(ss==se)return ss;
    int mid=ss+se>>1;
    int ans=Get(ls[p],ls[c],ss,mid);
    if(ans==-1)ans=Get(rs[p],rs[c],mid+1,se);
    return ans;
}

int main(){
    int n,q;scanf("%i %i",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%i",&a[i]);
        Set(root[i-1],root[i],1,n,a[i]);
    }
    while(q--){
        int l,r,k;scanf("%i %i %i",&l,&r,&k);
        need=(r-l+1)/k;
        printf("%i\n",Get(root[l-1],root[r],1,n));
    }
    return 0;
}