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
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,rez;
vector <ll> f;

int main()
{
    cin >> n;
    if (n%2 == 0)
       cout << (n/2) << endl;
    else
        cout << (n/2)-n << endl;
    return 0;
}