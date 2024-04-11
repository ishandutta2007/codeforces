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

ll n,i,j,x,y,a[100500],b[100500],used[100500],m,k1,k2,rez;
vector <ll> order,tmp;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i]--;
    }
    for (i = 0; i < m; i++)
        if (!used[b[i]])
        {
         used[b[i]] = 1;
         order.push_back(b[i]);
        }
    rez = 0;
    for (i = 0; i < m; i++)
    {
        j = 0;
        while (order[j] != b[i])
              rez += a[order[j++]];
        tmp.push_back(b[i]);
        for (j = 0; j < order.size(); j++)
        if (order[j]!=b[i]) tmp.push_back(order[j]);
        order.clear();
        for (j = 0; j < tmp.size(); j++)
            order.push_back(tmp[j]);
        tmp.clear();
        //for (j = 0; j < order.size(); j++)
        //    cout << order[j] << " ";
        //cout << endl;
        //cout << rez << endl;
    }
    cout << rez << endl;
    return 0;
}