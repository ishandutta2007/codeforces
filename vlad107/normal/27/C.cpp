#include <stdio.h>

int n,a[100500],m,nom[100500];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    nom[0]=1;m=1;
    for (int i=1;i<n;i++)
        if (a[i]!=a[i-1]){
            nom[m]=i+1;
            a[m]=a[i];
            m++;
        }
    for (int i=1;i<m-1;i++)
        if ((a[i]>a[i-1]&&a[i]>a[i+1])||
            (a[i]<a[i-1]&&a[i]<a[i+1])){
                printf("3\n%d %d %d\n",nom[i-1],nom[i],nom[i+1]);
                return 0;
            }
    printf("0\n");
}