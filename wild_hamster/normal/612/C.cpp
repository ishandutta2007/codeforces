#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[1000500];
string s;
ll Abs(ll x)
{
    return x>0?x:-x;
}
void error() {
    cout << "Impossible" << endl;
    exit(0);
}
vector <ll> f;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
    {
        if (s[i] == '{')
        {
            f.push_back(1);
        } else
        if (s[i] == '(')
        {
            f.push_back(2);
        } else
        if (s[i] == '[')
        {
            f.push_back(3);
        } else
        if (s[i] == '<')
        {
            f.push_back(4);
        } else
        if (s[i] == '}')
        {
            if (f.size() == 0)
                error();
            else
            if (f[f.size()-1] != 1)
                p++;
            f.pop_back();
        } else
        if (s[i] == ')')
        {
            if (f.size() == 0)
                error();
            else
            if (f[f.size()-1] != 2)
                p++;
            f.pop_back();
        } else
        if (s[i] == ']')
        {
            if (f.size() == 0)
                error();
            else
            if (f[f.size()-1] != 3)
                p++;
            f.pop_back();
        } else
        if (s[i] == '>')
        {
            if (f.size() == 0)
                error();
            else
            if (f[f.size()-1] != 4)
                p++;
            f.pop_back();
        }
    }
    if (f.size() == 0)
    cout << p << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}