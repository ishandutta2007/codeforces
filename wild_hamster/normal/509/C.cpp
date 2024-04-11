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
ll n,i,j,d,x,y,m,len,r,sum,a[1005];
string cur;
bool greater1(string x, string y)
{
       if (x.size() > y.size())
          return true;
       if (x.size() < y.size())
          return false;
       for (int i = 0; i < x.size(); i++)
           if (x[i] > y[i]) return true;
           else if (x[i] < y[i]) return false;
       return false;
}
string getNext(string x, ll n)
{
       ll i,j;
       string tmp;
       ll len = (n - 1)/9+1;
       tmp.push_back('0'+(n-1)%9+1);
       for (i = 0; i < len - 1; i++)
           tmp.push_back('9');
       //cout << tmp << endl;
       if (greater1(tmp,x))
          return tmp;
       ll k = x.size();
       for (i = k - 1; i >= 0; i--)
       {
           string y;
           ll sum = 0;
           for (j = 0; j < i; j++)
           {
               y.push_back(x[j]);
               sum += x[j] - '0';
           }
           if (sum+x[i]-'0' >= n || sum + (k-i)*9 < n || x[i] - '0' == 9)
              continue;
           
           ll digit = max(x[i]+1 -(ll)'0', n-sum-9*(k-i-1));   
           y.push_back(digit + '0');
           sum += digit;
           ll counter = k-i-1;
           ll lft = n - sum;
           
           //cout << y << " " << lft << " " << counter << endl;
           while (counter)
           {
                 if (counter*9 == lft)
                 {
                  lft -= 9;
                  y.push_back('9');
                 } else
                 if (lft > (counter-1)*9)
                 {
                  y.push_back(lft%9+'0');
                  lft -= lft%9;
                 } else
                 y.push_back('0');
                 counter--;
           }
           return y;
       }
       string y;
       y.push_back('1');
       ll counter = k;
           ll lft = n - 1;
           while (counter)
           {
                 if (counter*9 == lft)
                 {
                  lft -= 9;
                  y.push_back('9');
                 } else
                 if (lft > (counter-1)*9)
                 {
                  y.push_back(lft%9+'0');
                  lft -= lft%9;
                 } else
                 y.push_back('0');
                 counter--;
           }
           return y;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    len = (a[0] - 1)/9+1;
    cur.push_back('0'+(a[0]-1)%9+1);
    for (i = 0; i < len - 1; i++)
        cur.push_back('9');
    cout << cur << endl;
    for (i = 1; i < n; i++)
    {
        cur = getNext(cur,a[i]);
        cout << cur << endl;
    }
    return 0;
}