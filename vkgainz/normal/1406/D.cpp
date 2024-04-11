#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dif[100001];
ll seg[400005];
ll lazy[400005];
int n,sz;
ll negSum = 0;
ll a1;
void init(){
    sz = 1;
    while(sz<n-1) sz*=2;
}
void update(int l,int r,int x){
    ll f = 0;
    ll s = 0;
    if(l==0) a1+=x;
    if(l) {
        f = dif[l-1];
        dif[l-1]-=x;
        negSum+=min(0LL,dif[l-1])-min(f,0LL);
    }
    if(r<n-1){
        s = dif[r];
        dif[r]+=x;
        negSum+=min(0LL,dif[r])-min(s,0LL);
    }
    
}

int main(){
    scanf("%d",&n); 
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    a1 = a[0];
    for(int i=1;i<n;i++){
        dif[i-1] = a[i-1]-a[i];
    }
    for(int i=0;i<n-1;i++){
        negSum+=min(dif[i],0LL);
    }
    //ceil((a1-negSum)/2)
    int q; scanf("%d",&q);
    ll ans = ceil((a1-negSum)*1.0/2);
    
    printf("%lld\n",ans);
    for(int i=0;i<q;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        --l; --r; 
        update(l,r,x);
        ans = ceil((a1-negSum)*1.0/2);
        printf("%lld\n",ans);
    }

}