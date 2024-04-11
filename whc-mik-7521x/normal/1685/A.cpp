#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<int,int>mp;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),mp[a[i]]++;
        if(n&1)puts("NO");
        else{
            stable_sort(a+1,a+n+1);
            int ct=1;
            for(int i=1;i<=n;i+=2)b[i]=a[ct++];
            for(int i=2;i<=n;i+=2)b[i]=a[ct++];
            int pd=0;
            for(int i=2;i<=n;i++)if(b[i]==b[i-1])pd=1;
            if(pd)puts("NO");
            else{
                puts("YES");
                for(int i=1;i<=n;i++)printf("%d ",b[i]);
                puts("");
            }
        }
    }
    return  0;
}