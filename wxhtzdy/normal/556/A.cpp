#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    char s[n];scanf("%s",&s);
    int cnt0=0,cnt1=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(cnt1>0)ans++,cnt1--;
            else cnt0++;
        }else{
            if(cnt0>0)ans++,cnt0--;
            else cnt1++;
        }
    }
    printf("%i",n-ans*2);
    return 0;
}