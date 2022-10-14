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

ll def1,def2,def3,def4,atk1,atk2,atk3,atk4,n,i,j,k,x,y,m,k1,k2;
string s1, s2, s3;
int main()
{
    cin >> s1 >> s2 >> s3;
    s1.append(s2);
    sort(s1.begin(),s1.end());
    sort(s3.begin(),s3.end());
    if (s1 == s3)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}