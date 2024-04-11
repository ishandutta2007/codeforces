#include <bits/stdc++.h>
using namespace std;
int main()
{
      int k,n,w;
      scanf("%i%i%i",&k,&n,&w);
      printf("%i",max(0,k*w*(w+1)/2-n));
      return 0;
}