#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        for(int i=0;i<n;i++)scanf("%i",&b[i]);
        bool low=0,high=0,ok=1;
        for(int i=0;i<n;i++){
            if(a[i]<b[i]&&!high)ok=0;
            if(a[i]>b[i]&&!low)ok=0;
            if(a[i]==-1)low=1;
            if(a[i]==1)high=1;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}