#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int> lg(n),ll(n),rg(n),rl(n);
    for(int i=0;i<n;++i) {
        ll[i]=lg[i]=1;
        if(i-1>=0 && a[i]>a[i-1]) lg[i]=lg[i-1]+1;
        if(i-1>=0 && a[i]<a[i-1]) ll[i]=ll[i-1]+1;
    }
    for(int i=n-1;i>=0;--i) {
        rl[i]=rg[i]=1;
        if(i+1<n && a[i]>a[i+1]) rg[i]=rg[i+1]+1;
        if(i+1<n && a[i]<a[i+1]) rl[i]=rl[i+1]+1;
    }
    int mx=*max_element(rg.begin(),rg.end());
    int ans=0,x=0;
    for(int i=1;i<n-1;++i) {
        if(a[i]>a[i-1] && a[i]>a[i+1]) {
            if(lg[i]==mx && rg[i]==mx && mx%2==1 && rl[i+mx-1]<mx && ll[i-mx+1]<mx) {
                ++ans;
                x=i;
            }
        }
    }
    if(ans>1) ans=0;
    if(ans) {
        for(int i=0;i<n;++i) {
            if(i!=x && (rg[i]==mx || lg[i]==mx)) ans=0;
        }
    }
    cout<<ans<<endl;
}