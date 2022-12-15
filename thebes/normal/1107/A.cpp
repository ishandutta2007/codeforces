#include <bits/stdc++.h>
using namespace std;

int n, i, m;
string s;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        cin >> m >> s;
        if(m==2){
            if(s[0]<s[1]) printf("YES\n2\n%c %c\n",s[0],s[1]);
            else printf("NO\n");
        }
        else{
            printf("YES\n2\n");
            char c = s[0]; s.erase(s.begin());
            printf("%c %s\n",c,s.c_str());
        }
    }
    return 0;
}