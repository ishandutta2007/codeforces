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
ll n,i,j,d,m,x,r,y,p,k,max1,e,l,rez,a[100500],b[100500];
string s1,s2,s;

int main()
{
    cin >> s;
    n = s.size();
    for (i = 0; i < n-3; i++)
        if (s[i] == 'b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r')
           a[i] = 1;
    b[0] = 0;
    rez = 0;
    for (i = 0; i < n; i++)
        b[i+1] = b[i]+a[i];
    for (i = 0; i < n; i++)
        for (j = i+3; j < n; j++)
           if (b[j-2] - b[i] > 0)
           {
               rez++;
           }
        
    cout << rez << endl;
    return 0;
}