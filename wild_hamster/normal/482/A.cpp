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
ll i,j,n,rez,k,m,y,z,x,a[100];
string s;

int main()
{
    cin >> n >> k;
    for (i = 0; i < k; i++)
        if (i%2 == 0)
           cout << i/2+1 << " ";
        else
            cout << n-i/2 << " ";
    if (k%2 == 1)
    for (i = 0; i < n-k; i++)
        cout << k/2+i+2 << " ";
    else
    for (i = 0; i < n-k; i++)
        cout << n-k/2-i << " ";
    cout << endl;
    return 0;
}