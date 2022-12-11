#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],b[N],n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++)ans1=max(ans1,max(a[i],b[i])),ans2=max(ans2,min(a[i],b[i]));
        cout<<ans1*ans2<<endl;
    }
    return  0;
}