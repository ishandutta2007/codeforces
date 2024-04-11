#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        map<int,int> pref;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll tmp=0;
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j])ans+=tmp;
                tmp+=pref[a[j]];
            }
            pref[a[i]]++;
        }
        printf("%lld\n",ans);
    }
}