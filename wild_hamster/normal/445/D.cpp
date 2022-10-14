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
ll k,j,x,y,n,m,cnt,d,i,b[100600],a[100600],inva[100600],bd[100500];
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int main()
{
    cin >> n >> d >> x;
    initAB();
    for (i = 0; i < n; i++)
        inva[a[i]] = i;
   cnt = 0;
   for (i = 0; i < n; i++) if (b[i]) bd[++cnt] = i;
   for (i = 0; i < n; i++)
   {
       for (j = n; j >= n - 30; j--)
          if (j > 0 && inva[j] <= i && b[i-inva[j]] == 1)
          {
                cout << j << endl;
                break;
          } 
       if (j < n - 30)
       {
       ll max1 = 0;
       for (j = 1; j <= cnt&&bd[j] <= i; j++)
           max1 = max(max1,a[i-bd[j]]);
       cout << max1 << endl;
       }
   }
    return 0;
}