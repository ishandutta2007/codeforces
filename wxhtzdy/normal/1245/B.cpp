#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        char s[n+1];
        scanf("%s",&s);
        int old_a=a,old_b=b,old_c=c,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'&&b>0){cnt++,b--;continue;}
            if(s[i]=='P'&&c>0){cnt++,c--;continue;}
            if(s[i]=='S'&&a>0){cnt++,a--;continue;}
        }
        if(cnt>=(n+1)/2)printf("YES\n");
        else {printf("NO\n");continue;}
        a=old_a,b=old_b,c=old_c;
        char ans[n+1];
        for(int i=0;i<n;i++){
            if(s[i]=='R'&&b>0){cnt++,b--,ans[i]='P';continue;}
            if(s[i]=='P'&&c>0){cnt++,c--,ans[i]='S';continue;}
            if(s[i]=='S'&&a>0){cnt++,a--,ans[i]='R';continue;}
            ans[i]='A';
        }
        for(int i=0;i<n;i++){
            if(ans[i]!='A')continue;
            if(a>0){a--,ans[i]='R';continue;}
            if(b>0){b--,ans[i]='P';continue;}
            if(c>0){c--,ans[i]='S';continue;}
        }
        for(int i=0;i<n;i++)printf("%c",ans[i]);
        printf("\n");
    }
}