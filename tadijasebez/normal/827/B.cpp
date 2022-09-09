#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int main(){
    int i;
    scanf("%d%d",&n,&k);
    printf("%d\n",(n-1)/k*2+min((n-1)%k,2));
    for(i=2;i<=n;i++)printf("%d %d\n",i,max(i-k,1));
}