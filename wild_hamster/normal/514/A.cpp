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
#define x1 ldfjgldf
#define x2 lfhlgfjhklgh
#define y1 klfjdhgkldfjhkldf
#define y2 ldfjgkldfjgkldfjhl
#define MX 1000000
typedef long long ll;
using namespace std;
ll l,r,i,j,n,k,m,x,cons,a[100500];
string s,s1;
int main()
{
    cin >> s;
    i = 0;
    if (s[i] > '4' && s[i] < '9')
    {
     s1.push_back('9'-s[i]+'0');
    } else
    s1.push_back(s[i]);
    for (i = 1; i < s.size(); i++)
        if (s[i] > '4')
        {
           s1.push_back('9'-s[i]+'0');
        }
        else
        s1.push_back(s[i]);
    cout << s1 << endl;
   //system("pause");
    return 0;
}