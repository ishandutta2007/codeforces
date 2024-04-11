#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],n,m,j,p,k1,k2,k3,k,i,cur;
string s[8];
int main()
{
s[0] = "+------------------------+";
s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
s[3] = "|#.......................|";
s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
s[5] = "+------------------------+";
   cin >> k;
   if (k >= 3) s[3][1] = 'O', k--;
   if (k >= 1) k1 = (k-1)/3+1;
   if (k >= 2) k2 = (k-2)/3+1;
   if (k >= 3) k3 = (k-3)/3+1;
   for (i = 0; i < s[1].size(); i++)
       if (s[1][i] == '#'&& k1 > 0)
       {
        s[1][i] = 'O';
        k1--;
       }
   for (i = 0; i < s[2].size(); i++)
       if (s[2][i] == '#'&& k2 > 0)
       {
        s[2][i] = 'O';
        k2--;
       }
   for (i = 0; i < s[4].size(); i++)
       if (s[4][i] == '#'&& k3 > 0)
       {
        s[4][i] = 'O';
        k3--;
       }
   for (i = 0; i < 6; i++)
       cout << s[i] << endl;
   return 0;
}