#include <bits/stdc++.h>
using namespace std;
#define ll long long
int seg[2000005];
ll dp[500001];
ll ans[500001];
int n,sz;
void init() {
    sz = 1;
    while(sz<n) sz*=2;
    for(int i=0;i<=2*sz;i++) {
        seg[i] = -1;
    }
}
void upd(int i,int v) {
    seg[i+=sz] = v;
    while(i>1) {
        i/=2;
        seg[i] = max(seg[2*i],seg[2*i+1]);
    }
}
int query(int l,int r) {
    l+=sz, r+=sz;
    int ret = -1;
    while(l<r) {
        if(l%2) ret =max(ret,seg[l++]);
        if(r%2) ret = max(ret,seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
int main(){
    cin >> n;
    init();
    string s; cin >> s; 
    if(s[0]=='1') dp[0] = 1;
    else dp[0] = 0;
    for(int i=1;i<n;i++) {
        if(s[i]=='1') dp[i] = dp[i-1]+1;
        else dp[i] = 0;
    }
    ans[0] = dp[0];
    upd(dp[0],0);
    for(int l=1;l<n;l++) {
        //find first to the left with a greater dp
        int bef = query(dp[l]+1,n);       
        upd(dp[l],l);
        if(bef==-1) {
            ans[l] = dp[l]*1LL*(dp[l]+1)/2+(l-dp[l]+1)*1LL*dp[l];
            continue;
        }
        ans[l] = (l-bef-dp[l])*1LL*dp[l]+ans[bef]+dp[l]*1LL*dp[l];
    }
    ll ret = 0;
    for(int i=0;i<n;i++) ret+=ans[i];
    cout << ret << endl;
}