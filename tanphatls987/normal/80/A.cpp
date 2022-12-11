#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

int n,m,i,j,h[100]={0,1};
int main()
{
    scanf("%d%d",&n,&m);
    int ans=m-n+1;
    for(i=2;i<51;i++) if (!h[i])
    {
        for(j=i+i;j<51;j+=i) h[j]=1;
    }
    for(i=n;i<=m;i++) ans-=h[i];
    if ((ans==2)&&(!h[n])&&(!h[m])) cout<<"YES";else cout<<"NO";
}