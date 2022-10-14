#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,k;scanf("%i %i",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        map<int,int> was;
        int cnt=0;
        for(int i=0;i<n;i++)if(was[a[i]]==0)cnt++,was[a[i]]++;
        if(k==1){
            if(cnt>1)printf("-1\n");
            else printf("1\n");
        }else{
            int ans=1;
            while(cnt>k)ans++,cnt-=k-1;
            printf("%i\n",ans);
        }
    }
    return 0;
}