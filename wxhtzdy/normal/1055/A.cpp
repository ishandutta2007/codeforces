#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    scanf("%i %i",&n,&s);
    int a[n],b[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<n;i++)scanf("%i",&b[i]);
    if(a[0]==0){printf("NO");return 0;}
    if(a[s-1]==1){printf("YES");return 0;}
    if(b[s-1]==0){printf("NO");return 0;}
    for(int i=s;i<n;i++){
        if(a[i]==1&&b[i]==1){printf("YES");return 0;}
    }
    printf("NO");
    return 0;
}