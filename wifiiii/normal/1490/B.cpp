#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n),cnt(3);
        for(int i=0;i<n;++i) cin>>a[i],cnt[a[i]%3]++;
        int m=n/3,ans=0;
        while(cnt[0]!=cnt[1] || cnt[1]!=cnt[2]) {
            if(cnt[0]>m) ans+=cnt[0]-m,cnt[1]+=cnt[0]-m,cnt[0]=m;
            if(cnt[1]>m) ans+=cnt[1]-m,cnt[2]+=cnt[1]-m,cnt[1]=m;
            if(cnt[2]>m) ans+=cnt[2]-m,cnt[0]+=cnt[2]-m,cnt[2]=m;
        }
        cout<<ans<<endl;
    }
}