#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[105];
    scanf("%s",&a);
    int n=strlen(a),tmp1=0,tmp2=0,ans=0;
    for(int i=0;i<n;i++){
        if(a[i]=='Q')ans+=tmp2,tmp1++;
        else if(a[i]=='A')tmp2+=tmp1;
    }
    printf("%i",ans);
    return 0;
}