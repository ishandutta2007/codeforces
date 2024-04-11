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
const int MAXN = 100000;
map<string,bool>M;
int main()
{
    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        if (M[s])
            cout<<"YES\n";
        else
            cout<<"NO\n";
        M[s]=1;
    }
    return 0;
}