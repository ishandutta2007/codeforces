#include <iostream>
using namespace std;
int a[300005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans = 0;
    for(int i=1;i<=n;++i) if(a[i]!=a[1]) ans=max(ans,abs(i-1));
    for(int i=1;i<=n;++i) if(a[i]!=a[n]) ans=max(ans,abs(i-n));
    cout<<ans<<endl;
}