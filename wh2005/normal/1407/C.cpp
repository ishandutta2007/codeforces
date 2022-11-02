#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
int n,c[N];


int main(){
    scanf("%d",&n);
    int x=1;
    for(int y=2;y<=n;y++){
        int a,b;
        printf("? %d %d\n",x,y);fflush(stdout);
        scanf("%d",&a);
        printf("? %d %d\n",y,x);fflush(stdout);
        scanf("%d",&b);
        if(a>b) c[x]=a,x=y;
        else c[y]=b;
    }
    c[x]=n;
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
    return 0;
}