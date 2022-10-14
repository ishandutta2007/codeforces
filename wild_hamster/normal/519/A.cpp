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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[100500],b[100500],q,dr;
ll black,white;
char c;
int main()
{
    
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            cin >> c;
            if (c == 'Q') white += 9;
            if (c == 'R') white += 5;
            if (c == 'B') white += 3;
            if (c == 'N') white += 3;
            if (c == 'P') white += 1;
            
            if (c == 'q') black += 9;
            if (c == 'r') black += 5;
            if (c == 'b') black += 3;
            if (c == 'n') black += 3;
            if (c == 'p') black += 1;
        }
    if (white > black)
       cout << "White" << endl;
    else
    if (white < black)
       cout << "Black" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}