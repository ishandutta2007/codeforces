 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll n,m,k,j,p,pN,pM,a[2000][2000],i,x,rez,N[2000000],M[2000000];
double rak;
double binpow(double x, ll n)
{
 if (n == 0) return 1.;
    else
    {
        double tmp = binpow(x,n/2);
        if (n%2) return x*tmp*tmp;
        else return tmp*tmp;
    }      
}
int main()
{
    cin >> n >> m;
    rak = 0;
    for (i = 1; i < n; i++)
        {
            rak += binpow((double)(i)/(double)n,m); 
        }
    printf("%.15f\n",(double)n - rak);
    return 0;
}