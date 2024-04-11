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
ll i,a[500],rez,k,l,j;
string s;   

int main()
{
    cin >> s;
    cin >> k;
    if (k >= s.size())
        cout << ((k+s.size())/2)*2 << endl;
    else
    {
        ll rez1 = 0;
        for (l = 0; l < s.size()/2; l++)
           {
            for (i = 0; i < s.size() - 2*l; i++)
            {
                ll z = 1;
               for (j = i; j < i+l; j++)
                   if (s[j]!=s[j+l]) z = 0;
               if (z) rez1 = max(rez1,l);
            }
               
           } 
        rez = 0;
        for (i = 0; i <= (s.size()-k)/2; i++)
        {
            int z = 1;
            l = s.size() - 2*i - k;
            for (j = l; j < l+i; j++)
                if (s[j]!=s[j+i+k])
                    z = 0;
        if (z) rez = max(rez,i);
        }
        cout << max((rez + k)*2,rez1*2) << endl;
    }
    return 0;
}