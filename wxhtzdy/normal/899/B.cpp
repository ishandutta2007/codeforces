#include <bits/stdc++.h>
using namespace std;
int c[24]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int d[24]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int e[24]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    bool ok=0;
    for(int i=0;i<24;i++){
        bool same=1;
        for(int j=0;j<n;j++)if(a[j]!=c[(i+j)%24])same=0;
        if(same)ok=1;
        same=1;
        for(int j=0;j<n;j++)if(a[j]!=d[(i+j)%24])same=0;
        if(same)ok=1;
        same=1;
        for(int j=0;j<n;j++)if(a[j]!=e[(i+j)%24])same=0;
        if(same)ok=1;
    }
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}