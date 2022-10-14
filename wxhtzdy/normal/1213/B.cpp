#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        int pref[n];
        for(int i=n-1;i>=0;i--)pref[i]=(i==n-1?a[i]:min(pref[i+1],a[i]));
        int ans=0;
        for(int i=0;i<n-1;i++)ans+=pref[i+1]<a[i];
        printf("%i\n",ans);
    }
}