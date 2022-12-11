#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int n,a[N],t;
int main(){
    scanf("%d",&t);
    while(t--){
        pair<int,int>v[N];
        scanf("%d",&n);
        int ans=-1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int l=i-1,r=n-i;
            if(v[a[i]].first+v[a[i]].second+1==n)ans=max(ans,min(l,v[a[i]].first)+min(r,v[a[i]].second)+1);
            v[a[i]]={l,r};
        }
        printf("%d\n",ans);
    }
    return  0;
}