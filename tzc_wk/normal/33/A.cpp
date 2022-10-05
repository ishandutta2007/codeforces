#include <bits/stdc++.h>
using namespace std;
const int M=100100;
const int INF=2000000000;
int n,m,k,a[M];
int main(){
    cin>>n>>m>>k; 
    for (int i=1;i<=m;i++) a[i]=INF;
    for (int i=1,x,c;i<=n;i++){
        cin>>x>>c;
        a[x]=min(a[x],c);
    }
    int ans=0;
    for (int i=1;i<=m;i++) ans+=a[i];
    cout<<min(ans,k)<<endl;
    return 0;
}