#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],t,ans[N];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ct=0;
        for(int i=1;i<=n;i++){
            int o=i;
            while(a[o]==a[i]&&o<=n)o++;
            if(o==i+1)ct=1;
            for(int k=i+1;k<o;k++)ans[k]=k-1;
            ans[i]=o-1;
            i=o-1;
        }
        if(ct)puts("-1");
        else {for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");}
    }
    return  0;
}