#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int seg[200005];
int n;
void upd(int i,int v) {
    seg[i+=n] = v;
    while(i>1) {
        i/=2;
        seg[i] = min(seg[2*i],seg[2*i+1]);
    }
}
int query(int l,int r){
    int ret = 200000;
    l+=n, r+=n;
    while(l<r) {
        if(l%2) ret = min(ret,seg[l++]);
        if(r%2) ret = min(seg[--r],ret);
        l/=2, r/=2;
    }
    return ret;
}
int main() {
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) --a[i];
    bool mex[n+2];
    memset(mex,false,sizeof(mex));
    //if i included in mex, then [0,i-1] occurs in subarray without i occur
    //if answer is i+1, then i is included in mex but i+1 is not
    memset(seg,-1,sizeof(seg));
    int last[n+1];
    fill(last,last+n+1,-1);
    for(int i=0;i<n;i++) {
        int mn = query(0,a[i]);
        if(last[a[i]]<i-1 && mn>last[a[i]]) {
            mex[a[i]] = true;
        }
        upd(a[i],i);
        last[a[i]] = i;
    }
    for(int i=0;i<=n;i++) {
        int mn = query(0,i);
        if(last[i]<n-1 && mn>last[i]) mex[i] = true;
    }
    int ans = 0;
    for(int i=0;i<=n+1;i++) {
        if(!mex[i]) {
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
}