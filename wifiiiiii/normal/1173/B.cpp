
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    int n;
    cin>>n;
    int ans=1;
    while(ans*2-1<n) ans++;
    cout<<ans<<endl;
    int k = n;
        for(int i=1;i<ans;++i)
        {
            if(!k) break;
            cout<<1<<" "<<i<<endl;
            --k;
        }
        for(int i=1;i<=ans;++i)
        {
            if(!k) break;
            cout<<i<<" "<<ans<<endl;
            --k;
        }
    
}