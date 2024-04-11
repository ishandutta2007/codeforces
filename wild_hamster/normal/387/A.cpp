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
ll n,i,j,d,m,x,y,p,k,max1,a[105000],b[5000],e,l,rez,rows,cols;
string s1,s2,s;
int main()
{
    cin >> s1 >> s2;
    n = (s1[0]-'0')*600+(s1[1]-'0')*60+(s1[3]-'0')*10+s1[4]-'0';
    m = (s2[0]-'0')*600+(s2[1]-'0')*60+(s2[3]-'0')*10+s2[4]-'0';
    n = (n-m+1440)%1440;
    s.push_back(n/600+'0');
    n%=600;
    s.push_back(n/60+'0');
    n%=60;
    s.push_back(':');
    s.push_back(n/10+'0');
    n%=10;
    s.push_back(n+'0');
    cout << s << endl;
    return 0;
}