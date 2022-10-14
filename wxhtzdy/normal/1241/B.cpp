#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        bool ok=0;
        for(char c:a){
            for(char d:b)if(c==d)ok=1;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}