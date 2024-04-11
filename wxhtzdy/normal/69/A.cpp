#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[3]={0,0,0};
    for(int i=0;i<n;i++){
        int x,y,z;
        scanf("%i %i %i",&x,&y,&z);
        a[0]+=x,a[1]+=y,a[2]+=z;
    }
    if(a[0]==0&&a[1]==0&&a[2]==0)printf("YES\n");
    else printf("NO\n");
    return 0;
}