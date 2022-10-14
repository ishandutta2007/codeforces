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
ll i,j,n,a[100500],b[100500],c[100500],rez;
string s;
int main()
{
    cin >> n;
    rez = 2;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        b[i] = -1;
    i = 0;
    while (i < n)
    {
        j = i;
        while (i+1 < n&&a[i] < a[i+1])
            i++;
        rez = max(rez,i-j+2);
        ll r = i;
        while (r >= j) {b[r] = r-j+1;r--;}
        while (j <= i) c[j++] = i;
        i++;
        
    }
/*  cout << rez << endl;
    for (i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for (i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;*/
    for (i = 1; i < n-1; i++)
        if (a[i-1]+1 < a[i+1])
           rez = max(rez,b[i-1]+b[c[i+1]]-b[i+1]+2);
    cout << min(n,rez) << endl;
    return 0;
}