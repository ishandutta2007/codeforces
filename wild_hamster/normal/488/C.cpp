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
ll n,l,r,i,j,k,x,m,y,v,rez,a[100500],hp1,atk1,def1,hp2,atk2,def2;
ll hppr,atkpr,defpr;

int main()
{
    ll rez = (ll)1e+15;
    cin >> hp1 >> atk1 >> def1;
    cin >> hp2 >> atk2 >> def2;
    cin >> hppr >> atkpr >> defpr;
    ll tmp = 0;
    if (atk1 <= def2)
    {     
       tmp += (def2-atk1+1)*atkpr;
       atk1 += (def2-atk1+1);
    }
        for (j = atk1; j <= atk1+100; j++)
            for (k = def1; k <= 100; k++)
            {
                if (atk2-k <= 0)
                {
                 rez = min(rez, tmp+(j-atk1)*atkpr+(k-def1)*defpr);
                 continue;
                }
                ll damage1 = (hp2-1)/(j-def2) + 1;
                i = max(hp1,damage1*(atk2-k) + 1);
                rez = min(rez, tmp+(i-hp1)*hppr+(j-atk1)*atkpr+(k-def1)*defpr);
            }
    cout << rez << endl;
    return 0;
}