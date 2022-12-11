#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long int s[20000]={0},h[10]={0},n,m,k,i,j,x,y;
    short int a[20000][10];
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) cin>>a[i][j];
    for(i=0;i<k;i++)
    {
        scanf("%ld%ld",&x,&y);
        h[y-1]++;s[x-1]--;
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) if (a[i][j]) s[i]+=h[j];
    for(i=0;i<n;i++) printf("%ld ",s[i]);
}