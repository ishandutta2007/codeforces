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
using namespace std;
const int N = 1005;
string s, ss;
int main()
{
    cin>>s;
    ss = s;
    for (int i = s.size() - 1; i >= 0; i--)
        ss+=s[i];
    cout<<ss<<endl;
    return 0;
}