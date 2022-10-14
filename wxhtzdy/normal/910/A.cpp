#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    scanf("%i %i",&n,&d);
    char a[n+1];
    scanf("%s",&a);
    if(n==2){printf("1\n");return 0;}
    int pos=0,ans=0;
    bool ok=0;
    while(pos<n){
        int nxt=-1,cnt=1;
        for(int i=pos+1;i<n&&cnt<=d;i++){
            if(a[i]=='1')nxt=i;
            cnt++;
        }
        if(nxt==-1)break;
        pos=nxt,ans++;
        if(pos==n-1){ok=1;break;}
    }
    if(ok)printf("%i\n",ans);
    else printf("-1\n");
    return 0;
}