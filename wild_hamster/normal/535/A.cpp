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
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,x1,x2,x3,y1,y2,z,w,l,r,i,j,n,x,y,d,m,q,A,B,sz;
ll a[1400500],b[400500];
string s[20] = {"zero","one","two","three","four","five","six","seven","eight","nine",
"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string t[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int main()
{
    cin >> n;
    if (n < 20)
       cout << s[n] << endl;
    else
    {
        x = n/10;
        cout << t[x];
        if (n % 10 != 0)
           cout << "-" << s[n%10];
        cout << endl;
    }
    return 0;
}