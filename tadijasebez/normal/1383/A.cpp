#include <bits/stdc++.h>
using namespace std;
const int N=100050;
char s[N],t[N];
int main(){
    int tc;
    scanf("%i",&tc);
    while(tc--){
        int n;
        scanf("%i",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        bool ok=true;
        int ans=0;
        while(1){
            char a='z';
            bool all=true;
            for(int i=1;i<=n;i++){
                if(s[i]>t[i]){
                    ok=false;
                    break;
                }
                if(s[i]!=t[i]){
                    a=min(a,s[i]);
                    all=false;
                }
            }
            if(!ok||all)break;
            char b='z';
            for(int i=1;i<=n;i++){
                if(s[i]!=t[i]&&s[i]==a){
                    b=min(b,t[i]);
                }
            }
            ans++;
            for(int i=1;i<=n;i++){
                if(s[i]!=t[i]&&s[i]==a){
                    s[i]=b;
                }
            }
        }
        if(!ok)printf("-1\n");
        else printf("%i\n",ans);
    }
    return 0;
}