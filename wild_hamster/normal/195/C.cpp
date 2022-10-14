#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef int ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
ll a[200500], b[200500], t[400500], to_push[400500];
string s;
vector <string> f;
char c;
ll pos;
string lex;
void getChar()
{
    if (pos < s.size())
       c = s[pos++];
    else
        c = '\n';
}
bool isAlpha(char c)
{
    if (c >= 'a' && c <= 'z')
       return true;
    if (c >= 'A' && c <= 'Z')
       return true;
    return false;
}
void getLex()
{
    while (c == ' ')
          getChar();
    if (c == '(')
    {
        lex = "(";
        getChar();
    } else
    if (c == ')')
    {
        lex = ")";
        getChar();
    } else
    if (c == ',')
    {
        lex = ",";
        getChar();
    } else
    if (c == '"')
    {
        getChar();
        string tmp;
        while (c != '"')
        {
              tmp.push_back(c);
              getChar();
        }
        lex = tmp;
    } else
    {
        lex.clear();
        while (isAlpha(c))
        {
            lex.push_back(c);
            getChar();
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    getline(cin,s);
    string ans;
    for (i = 0; i < n; i++)
    {
        getline(cin,s);
        ll sz = s.size();
        if (sz == 0)
           continue;
        pos = 0;
        getChar();
        getLex();
        string x = lex;
        if (x == "try")
           k++;
        else
        if (x == "throw")
        {
            getLex();
            getLex();
            ans = lex;
            m = k;
        } else
        if (x == "catch")
        {
            getLex();
            getLex();
            if (lex == ans && m == k)
            {
                getLex();
                //cout << lex << endl;
                getLex();
                cout << lex << endl;
                return 0;
            }
            k--;
            m = min(m,k);
        }
    }
    cout << "Unhandled Exception" << endl;
    return 0;
}