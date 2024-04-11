#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n),b(n),ord(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int i,int j){return a[i]<a[j];});
        int ans=0,x=1,y=1;
        for(int i:ord) {
            int nx=a[i],ny=b[i];
            if(x==nx && ny==y);
            else {
                assert(nx>x); assert(nx-x>=ny-y);
                int cnt1 = (nx-x)-(ny-y), cnt2 = nx-x-cnt1;
                if(cnt1) {
                    if((x+y)%2) --cnt1,++ans;
                    ans+=cnt1/2;
                } else {
                    if((x+y)%2==0) ans+=cnt2;
                }
            }
            x=nx,y=ny;
        }
        cout<<ans<<endl;
    }
}