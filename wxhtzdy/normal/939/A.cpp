#include <bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N];
int main(){
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),--a[i];
    bool ok=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(a[i]==j&&a[a[j]]==i)ok=1;
        }
    }
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}