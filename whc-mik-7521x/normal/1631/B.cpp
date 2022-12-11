#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N];
bool check(){
    int now=a[1];
    for(int i=1;i<=n;i++)if(a[i]!=now)return 0;
    return 1;
}
void solve(){
    int now=n;
    while(a[now]==a[n])now--;
    int len=n-now;
    for(int i=max(1,n-len*2+1);i<=n;i++)a[i]=a[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        while(!check()){ans++,solve();}
        cout<<ans<<endl;
    }
    return  0;
}