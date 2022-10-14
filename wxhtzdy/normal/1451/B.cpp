#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,q;scanf("%i %i",&n,&q);
        char s[n];scanf("%s",&s);
        int pref[n];
        for(int i=0;i<n;i++){
            if(i==0)pref[i]=s[i]=='1';
            else pref[i]=pref[i-1]+s[i]=='1';
        }
        while(q--){
            int l,r;scanf("%i %i",&l,&r);
            --l;--r;
            bool ok=0;
            for(int i=0;i<l;i++)if(s[i]==s[l])ok=1;
            for(int i=r+1;i<n;i++)if(s[i]==s[r])ok=1;
            if(ok)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}