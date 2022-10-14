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
ll x,y,n;

int main()
{
    cin >> x >> y;
    cin >> n;
    if (n%6 == 1) cout << (x+5LL*tr)%tr << endl;
    if (n%6 == 2) cout << (y+5LL*tr)%tr << endl;
    if (n%6 == 3) cout << (y-x+5LL*tr)%tr << endl;
    if (n%6 == 4) cout << (-x+5LL*tr)%tr << endl;
    if (n%6 == 5) cout << (-y+5LL*tr)%tr << endl;
    if (n%6 == 0) cout << (-y+x+5LL*tr)%tr << endl;    
    return 0;
}