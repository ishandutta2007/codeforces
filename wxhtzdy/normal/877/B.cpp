#include <bits/stdc++.h>
using namespace std;
const int N=5050;
char s[N];
int main(){
    scanf("%s",&s);
    int n=(int)strlen(s),ans=0,c1=0,c2=0,c3=0;
    int suf[n];
    for(int i=n-1;i>=0;i--){
        if(i<n-1)suf[i]=suf[i+1];
        else suf[i]=0;
        if(s[i]=='a')suf[i]++;
        if(s[i]=='b')ans++;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='b')c2++;
        for(int j=i+1;j<n;j++){
            if(s[j]=='a')c3++;
            ans=max(ans,c2+c3);
        }
        c3=0;
    }
    c2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a')c1++;
        ans=max(ans,c1);
        for(int j=i+1;j<n;j++){
            if(s[j]=='b')c2++;
            if(j==n-1)c3=0;
            else c3=suf[j];
            ans=max(ans,c1+c2+c3);
        }
        c2=0;
    }
    printf("%i",ans);
    return 0;
}