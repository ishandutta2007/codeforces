#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        char s[N];
        scanf("%s",s+1);
        n=strlen(s+1);
        long long ans=0;
        for(int i=1;i<=n;i++)ans+=s[i]-'a'+1;
        if(n%2){
            ans-=2*(min(s[1],s[n])-'a'+1);
            printf(ans>0?"Alice %lld\n":"Bob %lld\n",llabs(ans));
        }
        else{
            printf("Alice %lld\n",ans);
        }
    }
    return  0;
}