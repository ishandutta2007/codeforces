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
string s;
int n, m;
int main()
{
    cin>>s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'o')
            n++;
        else
            m++;
    }
    if (n == 0 || m % n == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}