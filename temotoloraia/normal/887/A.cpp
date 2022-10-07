#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int main()
{
    string s;
    cin>>s;
    int p = (int)s.size();
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1'){
            p = i;
            break;
        }
    int x = 0;
    for (int i = p; i < s.size(); i++)
        if (s[i] == '0')
            x++;
    if (x >= 6)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}