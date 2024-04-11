#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        char s[n];
        scanf("%s",&s);
        int cnt1=0,cnt2=0;
        for(int i=0;i<n-1;i++)cnt1+=s[i]=='1'&&s[i+1]=='1';
        for(int i=0;i<n-1;i++)cnt2+=s[i]=='0'&&s[i+1]=='0';
        printf("%i\n",max(cnt1,cnt2));
    }
    return 0;
}