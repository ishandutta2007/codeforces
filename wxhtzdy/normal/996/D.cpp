#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    n*=2;
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int ans=0;
    for(int i=0;i<n;i+=2){
        int id;
        for(int j=i+1;j<n;j++)if(a[i]==a[j])id=j;
        while(id>i+1)swap(a[id],a[id-1]),id--,ans++;
    }
    printf("%i",ans);
    return 0;
}