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
ll a[100500],used[1000],n,m,j,p,k1,k2,k3,k,i,cur;
string s,s1,s2;
char c;
int main()
{
    cin >> c;
    cin >> s;
    s1 = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (i = 0; i < s.size(); i++)
        for (j = 0; j < s1.size(); j++)
        if (s[i] == s1[j])
        {
                 //cout << s[i] << " ";
                 if (c == 'R')
                    s2.push_back(s1[j-1]);
                 else
                     s2.push_back(s1[j+1]);
        }
    cout << s2 << endl;
   return 0;
}