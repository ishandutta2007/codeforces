#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,sz;
int segmax[800000];
int segmin[800000];
int a[400000];
void init(){
    sz = 1;
    while(sz<2*n) sz*=2;
    for(int i=0;i<800000;i++){
        segmin[i] = 1000000000;
    }
}
void build(int x=0,int lx=0,int rx=sz){
    if(rx-lx==1){
        segmin[x] = a[lx];
        segmax[x] = a[lx];
    }
    else{
        int m = (lx+rx)/2;
        build(2*x+1,lx,m);
        build(2*x+2,m,rx);
        segmin[x] = min(segmin[2*x+1],segmin[2*x+2]);
        segmax[x] = max(segmax[2*x+1],segmax[2*x+2]);
    }
}
int queryMin(int l,int v,int x=0,int lx=0,int rx=sz){
    if(rx-lx==1){
        if(lx>=l && segmin[x]<=v) return lx;
        else return 1000000000;
    }
    if(rx<=l) return 1000000000;
    if(lx>=l){
        if(segmin[x]<=v){
            if(segmin[2*x+1]<=v) return queryMin(l,v,2*x+1,lx,(lx+rx)/2);
            return queryMin(l,v,2*x+2,(lx+rx)/2,rx);
        }
        else return 1000000000;
    }
    int m = (lx+rx)/2;
    return min(queryMin(l,v,2*x+1,lx,m),queryMin(l,v,2*x+2,m,rx));
}
int queryMax(int l,int v,int x=0,int lx=0,int rx=sz){
    if(rx<=l) return 1000000000;
    if(lx>=l){
        if(segmin[x]>=v) return lx;
        else return 1000000000;
    }
    int m = (lx+rx)/2;
    return min(queryMax(l,v,2*x+1,lx,m),queryMax(l,v,2*x+2,m,rx));
}



int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) a[n+i] = a[i];
    init();
    build();
    int ans[n];
    memset(ans,-1,sizeof(ans));
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            int high = 0;
            int low = 1000000000;
            for(int i=n-1;i<3*n;i++){
                low = min(low,a[i%n]);
                if(a[i%n]>high){
                    low= a[i%n];
                    high = a[i%n];
                }
                if(low<=(high-1)/2){
                    ans[n-1] = i-(n-1);
                    break;
                }
            }
        }
        else{
            int v = (a[i]-1)/2;
            int idx = queryMin(i,v);
            if(idx>=2*n){
                if(ans[i+1]==-1) ans[i] = -1;
                else ans[i] = ans[i+1]+1;
            }
            else{
                if(ans[i+1]==-1) ans[i] = idx-i;
                else
                    ans[i] = min(idx-i,ans[i+1]+1);
            }

        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
}