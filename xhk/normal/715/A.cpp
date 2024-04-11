#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n;

int main()
{int i,j,k;
 
 scanf("%d",&n);
 k=2;
 for(i=1;i<=n;i++)
 {	printf("%I64d\n",(ll)i*(i+1)*(i+1)-k);
 	k=i;
 }
 return 0;
}