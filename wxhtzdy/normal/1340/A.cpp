#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        map<int,int> pos;
        for(int i=0;i<n;i++)scanf("%i",&a[i]),pos[a[i]]=i;
        int tr=pos[1];
        bool was[n];
        for(int i=0;i<n;i++)was[i]=0;
        was[tr]=1;
        bool ok=1;
        for(int i=2;i<=n;i++){
            int x=pos[i];
            if(tr==(n-1)||was[tr+1]){
                was[x]=1;
                tr=x;
            }else{
                if((tr+1)!=x)ok=0;
                was[x]=1;
            }
        }
        if(ok)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}