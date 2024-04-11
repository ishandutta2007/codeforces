#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,r,y,p,k,max1,e,l,rez;
string s1,s2,s;

int main()
{
    cin >> s1 >> s2;
    for (i = 0; i < s1.size(); i++)
        if (s1[i] == '+') rez++;
           else rez--;
    for (i = 0; i < s2.size(); i++)
         if (s2[i] == '+') rez--;
           else if (s2[i] == '-') rez++;     
           else n++;
    for (i = 0; i < (1<<n); i++)
    {
        ll tmp = 0;
        for (j = 0; j < n; j++)
            if ((i&(1<<j)) > 0)
               tmp++;
            else
                tmp--;
        if (tmp == rez) m++;
    }
    double rezz = (double)m/(1<<n);
    printf("%.10f\n",rezz);
    return 0;
}