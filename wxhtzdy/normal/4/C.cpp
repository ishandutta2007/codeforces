#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    map<string,int> mp;
    map<string ,int> nxt;
    for(int i=0;i<n;i++){
        char a[35];
        scanf("%s",&a);
        if(!mp[a]){
            printf("OK\n");
            mp[a]=1;
            nxt[a]=1;
        }else{
            printf("%s%i\n",a,nxt[a]);
            nxt[a]++;
        }
    }
}