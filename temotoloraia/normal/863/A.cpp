#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
string s;
int main()
{
    cin>>s;
    int n = (int)s.size();
    int x = 0, y = n - 1;
    while (s[x]=='0' && x<n-1)
        x++;
    while (s[y]=='0' && y>0)
        y--;
    if (x > n - 1 - y){
        cout<<"NO\n";
        return 0;
    }
    string s1="",s2="";
    for (int i=x;i<=y;i++)
        s1+=s[i];
    for (int i=y;i>=x;i--)
        s2+=s[i];
    if (s1==s2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}