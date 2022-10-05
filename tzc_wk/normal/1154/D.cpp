#include <bits/stdc++.h>
using namespace std;
int n,a,b;
bool s[200003];
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    int ans=0,ca=a,cb=b;
    for(int i=0;i<n;i++){
        if(s[i]==0){
            if(cb>0)		cb--,ans++;
            else if(ca>0)	ca--,ans++;
            else			break;
        }
        else{
            if(ca>0&&cb<b)	ca--,cb++,ans++;
            else if(cb>0)	cb--,ans++;
            else			break;
        }
    }
    printf("%d\n",ans);
}