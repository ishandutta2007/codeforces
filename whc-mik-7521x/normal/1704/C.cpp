#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)scanf("%d",&a[i]);
        stable_sort(a+1,a+m+1);
        vector<int>vec;
        for(int i=1;i<m;i++)vec.push_back(a[i+1]-a[i]-1);
        vec.push_back(n-a[m]+a[1]-1);
        stable_sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int ans=0,ct=0;
        for(int i:vec){
            ans+=max(0,i-ct==1?1:i-ct-1);
            ct+=4;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}