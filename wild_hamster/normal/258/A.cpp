#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll k,j,x,y,n,m,cnt,d,i,b[100600],a[100600],inva[100600],bd[100500];
string s;
int main()
{
    cin >> s;
    m = s.size()-1;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') { m=i; break;}
    }
    for (i = 0; i < s.size(); i++)
        if (i!=m) cout << s[i];
  //  system("pause");
    return 0;
}