#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const int N = 3005;
string s;
int a[N];
int main()
{
    cin>>s;
    char ch = s[0];
    for (int i = 1; i < s.size(); i++)
        if (s[i] < ch)
            ch = s[i];
    for (int i = 1; i < s.size(); i++)
        if (s[i] != ch && s[i - 1] == ch || s[i] == ch && s[i - 1] != ch)
            a[i] = 1;
    if (s[s.size() - 1] == ch)
        a[s.size()] = 1;
    for (int i = 1; i <= s.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}