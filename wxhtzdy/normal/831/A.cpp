#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    bool can=1;
    int j=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]&&can)j=i;
        else{
            if(a[i]==a[i-1])j=i,can=0;
            else break;
        }
    }
    bool ok=1;
    for(int i=j+1;i<=n;i++)if(a[i]>=a[i-1])ok=0;
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}