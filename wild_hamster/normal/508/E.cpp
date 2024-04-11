#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,d,x,k,y,m,l[1005],r[1005],len[1005],sum,rez;
vector <ll> lalka;
string s;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        s.push_back('(');
        lalka.push_back(i);
        len[i] = s.size() - 1;
        while (!lalka.empty() && len[lalka[lalka.size()-1]] + l[lalka[lalka.size()-1]] <= s.size())
        {
              if (len[lalka[lalka.size()-1]] + r[lalka[lalka.size()-1]] < s.size())
              {
               cout << "IMPOSSIBLE" << endl;
               return 0;
              }
              s.push_back(')');
              lalka.pop_back();
        }
    }
    if (lalka.empty())
    cout << s << endl;
    else
    cout << "IMPOSSIBLE" << endl;
    return 0;
}