 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll n,m,k,j,p,pN,pM,a[2000][2000],i,x,rez,N[2000000],M[2000000];
string s;
multiset <ll> setM,setN;
multiset <ll>::iterator itrM, itrN;
int main()
{
    
    cin >> n >> m >> k >> p;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
    {
        ll tmp = 0;
        for (j = 0; j < m; j++)
            tmp += a[i][j];
        setN.insert(tmp);
    }
    for (j = 0; j < m; j++)
    {
        ll tmp = 0;
        for (i = 0; i < n; i++)
            tmp += a[i][j];
        setM.insert(tmp);
    }
    ll rez1 = 0, rez2 = 0;
    rez = -(ll)1e+18;
    pM = pN = 0;
    for (i = 0; i < k; i++)
    {      
        {
           M[i] = rez2;
           itrM = setM.end(); itrM--; ll tmpM = (*itrM);
           rez2 = rez2 + (ll)tmpM;
           tmpM -=p*n;
           setM.erase(itrM);
           setM.insert(tmpM);
        }
        {
           N[i] = rez1;
           itrN = setN.end(); itrN--; ll tmpN = (*itrN);
           rez1 = rez1 + (ll)tmpN;
           tmpN -=p*m;
           setN.erase(itrN);
           setN.insert(tmpN);
           
        }
    }
    M[i] = rez2; N[i] = rez1;
    /*for (i = 0; i <= k; i++)
        cout << M[i] << " " << N[i] << endl;*/

    for (i = 0; i <= k; i++)
        rez = max(rez,N[i]+M[k-i]-(k-i)*i*p);
    cout << rez << endl;
    return 0;
}