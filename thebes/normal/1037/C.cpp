#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;
string s, t;
int d[MN], d2[MN], c[MN], ans, n, i;

int main(){
    cin >> n >> s >> t;
    for(i=0;i<n;i++){
        if(s[i]!=t[i]) ans++, c[i]=(s[i]>t[i])?1:-1;
        else d[i]=1, d2[i]=1;
    }
    for(i=0;i<n;i++){
        if(c[i]&&c[i+1]&&c[i]!=c[i+1])
            ans--, c[i]=c[i+1]=0;
    }
    printf("%d\n",ans);
    return 0;
}