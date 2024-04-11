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

#pragma comment(linker, "/STACK:1677721600")

const long long MH = 987654321981;

long long cou(string& str)
{
    long long st3(1);
    long long has(0);
    for(int i(0); i < str.size(); ++i)
    {
        has += st3 * (str[i] - 'a');
        st3 *= 3;
        st3 %= MH;
    }
    has %= MH;
    return has;
}


struct node
{
    int len;
    long long has;

    node(string& str) : len(str.size()), has(cou(str)){};
    node(){};
};

struct comp
{
    bool operator() (const node& f, const node& s)
    {
        return (f.len != s.len ? f.len > s.len : f.has > s.has);
    }
};
node not;
long long st3;
string s;
set<node, comp> mas;

void take()
{
    cin >> s;
    not.len = s.size();
    not.has = cou(s);
    st3 = 1;
    for(int i(0); i < not.len; ++i, st3 *= 3, st3 %= MH)
    {
        if(s[i] == 'a')
        {
            not.has += st3;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += st3;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += (MH - st3) * 2;
            not.has %= MH;
        }
        else if(s[i] == 'b')
        {
            not.has += st3;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += (MH - st3) * 2;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += st3;
            not.has %= MH;
        }
        else
        {
            not.has += MH - st3;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += MH - st3;
            not.has %= MH;
            if(mas.find(not) != mas.end())
            {
                cout << "YES\n";
                return;
            }
            not.has += st3 * 2;
            not.has %= MH;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i(0); i < n; ++i)
    {
        cin >> s;
        mas.insert(node(s));
    }
    while(m--)
        take();
    return 0;
}

//ababababaabababababbababababbababababbababababbababaaababaababaabaababababbabababaabababaaabc