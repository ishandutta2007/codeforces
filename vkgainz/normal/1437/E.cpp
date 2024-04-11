#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int lis(vector<int> &a) {
    int n = a.size();
    const int INF = 2e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;
    for(int i=0;i<n;i++) {
        int j = upper_bound(d.begin(),d.end(),a[i])-d.begin();
        if(d[j-1] <= a[i] && a[i]<=d[j]) d[j] = a[i];
    }
    int ans = 0;
    for(int i=0;i<=n;i++) {
        if(d[i]<INF) ans = i;
    }
    return ans;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) a[i]+=n-i;
    vector<int> b;
    for(int i=0;i<k;i++) {
        int x; scanf("%d",&x);
        b.push_back(--x);
    }
    vector<int> in;
    int l = 0, r = n;
    int ans = 0;
    bool work = true;
    if(k>0) {
        l = 0, r = a[b[0]];   
        if(l>r) work = false;
        for(int i=0;i<b[0] && work;i++) {
            if(a[i]>=l && a[i]<=r) in.push_back(a[i]);
        }
        ans+=b[0]-lis(in);
        in.clear();
        l = a[b[k-1]], r = 2e9;
        if(l>r) work = false;
        for(int i=b[b.size()-1]+1;i<n && work;i++) {
            if(a[i]>=l && a[i]<=r) in.push_back(a[i]);
        }
        ans+=n-1-b[k-1]-lis(in);
        in.clear();
    }
    else {
        l = 0, r = 2e9;
        for(int i=0;i<n;i++) in.push_back(a[i]);
        ans = n-lis(in);
    }
    for(int i=0;i<k-1;i++) {
        l = a[b[i]], r = a[b[i+1]];
        if(l>r) {
            work = false;
            break;
        }
        for(int j=b[i]+1;j<b[i+1];j++) {
            if(a[j]>=l && a[j]<=r) in.push_back(a[j]);
        }
        ans+=b[i+1]-b[i]-1-lis(in);
        in.clear();
    }
    if(!work) cout << -1 << endl;
    else cout << ans << endl;
}