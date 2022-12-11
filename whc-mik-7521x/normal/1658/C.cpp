#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ct1=0,aim=0;
        for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]==1)ct1++,aim=i;}
        if(ct1!=1){puts("NO");continue;}
        vector<int>v;
        for(int i=aim;i<=n;i++)v.push_back(a[i]);
        for(int i=1;i<aim;i++)v.push_back(a[i]);
        int pd=0;
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]>1)pd=1;
        }
        puts(pd?"NO":"YES");
    }
    return  0;
}