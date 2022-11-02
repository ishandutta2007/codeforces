#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,used[1111];
char a[111][111],b[111][111];
bool sw;
void check(){
    memset(used,-1,sizeof(used));
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if ((a[i][j]=='.')&&(used[j]<0))used[j]=i;
    for (int i=0;i<n;i++)
        if (used[i]<0)
            return;
    for (int i=0;i<n;i++){
        int x=used[i],y=i;
        if (sw)swap(x,y);
        printf("%d %d\n",x+1,y+1);
    }    
    exit(0);
}
int main(){
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)a[i][j]=getchar();
        if (i<n-1)scanf("\n");
    }
    for (int i=0;i<n;i++){
        int j=0;
        while ((j<n)&&(a[i][j]=='E'))j++;
        if (j==n){
            sw=true;
            break;
        }
    }
    sw=false;
    check();
    sw=true;
    for (int i=0;i<n;i++)for (int j=0;j<n;j++)b[i][j]=a[i][j];
    for (int i=0;i<n;i++)for (int j=0;j<n;j++)a[i][j]=b[j][i];
    check();
    puts("-1");
}