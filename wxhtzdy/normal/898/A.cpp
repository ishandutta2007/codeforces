#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n;scanf("%i",&n);
    if(n%10<=5)printf("%i",n-n%10);
    else printf("%i",n+10-n%10);
}