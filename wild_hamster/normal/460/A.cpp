#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll n,m,i,j,rez;
int main()
{
   cin >> n >> m;
   rez = 0;
   while (n)
   {
         n--;
         rez++;
         if (rez%m == 0) n++;
   }
   cout << rez << endl;

    return 0;
}