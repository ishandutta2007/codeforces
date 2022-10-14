#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,m;
        scanf("%i %i",&n,&m);
        int a[n],b[m];
        map<int,int> pos;
        for(int i=0;i<n;i++)scanf("%i",&a[i]),pos[a[i]]=i;
        for(int i=0;i<m;i++)scanf("%i",&b[i]);
        int lst=-1;
        long long ans=0;
        for(int i=0;i<m;i++){
            if(pos[b[i]]<=lst)ans++;
            else ans+=1+2*(pos[b[i]]-i),lst=pos[b[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}