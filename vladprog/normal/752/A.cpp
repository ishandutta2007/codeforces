#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG

#define ll long long

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&n,&k);
    k--;
    printf("%d %d %c",k/2/n+1,k/2%n+1,(k%2)?'R':'L');
}