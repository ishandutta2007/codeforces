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
ll sum,x1,x2,a1,b1,k,j,x,m,rez1,rez2,cnt,d,i,n,a[100500],rez[100500];
map <ll,ll> isAB;
vector <ll> f;
int dfs(int y)
{
    //cout << y << endl;
    //if (isAB[y] == 0) return 0;
    if (isAB[y] == tB) 
    {
    isAB[b1-y] = tB;
    return 1;
    }
    if (isAB[b1-y] == tB) 
    {
    isAB[y] = tB;
    return 1;
    }
    if (isAB[b1-y] == 0)
       return 0;
    else
    if (isAB[b1-y] == 1)
    {
     isAB[y] = tB;
     isAB[b1-y] = tB;
     return 1;
    } else
    {
        isAB[y] = tB;
        isAB[b1-y] = tB;
        return dfs(a1-b1+y);
    }
}
int main()
{
    cin >> n >> a1 >> b1;
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        isAB[a[i]] = 1;
    }
        
    
    for (i = 0; i < n; i++)
    {
        if (isAB[a1-a[i]] == 1)
        {
           isAB[a[i]] = tA; 
           isAB[a1-a[i]] = tA;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (isAB[a[i]] == 1)
        {
         int x = dfs(a[i]);
         if (x == 0)
         {
                cout << "NO" << endl;
                return 0;
         }
        }
         
    }  
    
    cout << "YES" << endl;
    for (i = 0; i < n; i++)
    if (isAB[a[i]] == tA) cout << 0 << " ";
    else cout << 1 << " ";
    return 0;
}