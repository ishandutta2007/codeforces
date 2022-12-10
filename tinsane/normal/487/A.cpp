#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <list>
using namespace std;
//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")

struct pers
{
    int hp, def, att;
};

int main(){
    ios_base::sync_with_stdio(0);
    pers yan, mon;
    int hpr, dpr, apr, minpr(MAXINT), res(0),  best[300][300];
    cin >> yan.hp >> yan.att >> yan.def >> mon.hp >> mon.att >> mon.def >> hpr >> apr >> dpr;
    yan.att -= mon.def;
    if(yan.att <= 0)
    {
        res += (1 - yan.att) * apr;
        yan.att = 1;
    }
    for(int i(yan.att); i < 300; ++i)
    for(int j(0); j <= mon.att; ++j)
    {
        int locr = (MAX(0, j - yan.def)) * dpr + (i - yan.att) * apr;
        int ts = mon.hp / i;
        if(mon.hp % i)
            ++ts;
        int oph = ts * (mon.att - j) + 1;
        locr += MAX(0, (oph - yan.hp) * hpr);
        minpr = MIN(minpr, locr);
    }
    cout << res + minpr;
    return 0;
}