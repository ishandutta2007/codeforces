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
ll n,i,j,d,m,x,r,y,p,k,max1,e,l;
string s1,s2,s;
ll rak[6][6];
long long base[6][6] = {

{2,1,1,0,1,0},

{1,2,0,1,1,0},

{1,1,1,0,1,0},

{1,1,0,1,1,0},

{0,0,0,0,1,1},

{0,0,0,0,0,1} };
void binpow(ll x)
{
 if (x == 0)
    return;
 ll b[6][6];
 ll i,j,k;
 binpow(x/2);
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
         b[i][j] = 0;
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
         for (k = 0; k < 6; k++)
         b[i][j] += (rak[i][k]*rak[k][j]+n)%n;
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
     {
         rak[i][j] = b[i][j];
         b[i][j] = 0;
     }
 if (x%2 == 1)
 {
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
         for (k = 0; k < 6; k++)
         b[i][j] += (rak[i][k]*base[k][j]+n)%n;
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
         rak[i][j] = b[i][j];
 }
 for (i = 0; i < 6; i++)
     for (j = 0; j < 6; j++)
     if (rak[i][j] > n)
         rak[i][j] = (ll)(rak[i][j]+n)%n;
}
int main()
{
    ll sx,sy,dx,dy,t;
    cin >> n >> sx >> sy >> dx >> dy >> t;
    for (i = 0; i < 6; i++)
        rak[i][i] = 1;
    binpow(t);
    /*for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
            cout << rak[i][j] << " ";
        cout << endl;
    }*/
    ll rez1 = 0, rez2 = 0;
    //cout << rak[0][4]<< endl;
    rez1 = (sx*rak[0][0]+n)%n+(sy*rak[0][1]+n)%n+(dx*rak[0][2]+n)%n+(dy*rak[0][3]+n)%n+rak[0][5]+n;
    rez2 = (sx*rak[1][0]+n)%n+(sy*rak[1][1]+n)%n+(dx*rak[1][2]+n)%n+(dy*rak[1][3]+n)%n+rak[1][5]+n;
    cout << (rez1-1+n)%n+1 << " " << (rez2-1+n)%n+1 << endl;
    return 0;
}