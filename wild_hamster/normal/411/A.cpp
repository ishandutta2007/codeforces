#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll n,i,j,x,y,a[200500],to[200500],c[200500],m,k1,k2,used[100500];
string s;
int main()
{
    cin >> s;
    ll flag = 1;
    if (s.size() < 5) flag = 0;
    ll z = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
           z = 1;
    flag &= z;
    
    z = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
           z = 1;
    flag &= z;
    
    z = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
           z = 1;
    flag &= z;
    if (flag)
       cout << "Correct" << endl;
    else
        cout << "Too weak" << endl;
    return 0;
}