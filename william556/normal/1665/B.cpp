#include<bits/stdc++.h>
using namespace std;
inline int in(){
    int x;
    scanf("%d",&x);
    return x;
}
const int N=1e5+5;
int n,a[N];
void solve(){
    n=in();
    for(int i=1;i<=n;i++)a[i]=in();
    sort(a+1,a+n+1);
    int mx=0;
    for(int i=1,j;i<=n;i=j+1){
        j=i;
        while(j<n&&a[j+1]==a[i])j++;
        mx=max(mx,j-i+1);
    }
    int ans=0;
    while(mx<n){
        ans+=1+min(n-mx,mx);
        mx<<=1;
    }
    cout<<ans<<endl;
}
int main(){
    int t=in();
    while(t--)solve();
    return 0;
}