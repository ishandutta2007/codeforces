#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int>v;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            v.push_back(a[i]);
        }
        stable_sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int m=v.size();
        for(int i=1;i<=m;i++)printf("%d ",m);
        for(int i=m+1;i<=n;i++)printf("%d ",i);
        puts("");
    }
    return  0;
}