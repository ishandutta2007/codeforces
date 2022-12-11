#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        vector<int>v1,v2;
        for(int i=1;i<=n;i++){
            if(a[i]%2==0)v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }
        int pd=0;
        for(int i=1;i<v1.size();i++)if(v1[i]<v1[i-1])pd=1;
        for(int i=1;i<v2.size();i++)if(v2[i]<v2[i-1])pd=1;
        puts(pd?"NO":"YES");
    }
    return  0;
}