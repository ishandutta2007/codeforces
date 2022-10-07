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
const int N = 100005;
int n;
string s;
main()
{
    cin>>n>>s;
    if (n == 1 && s[0] == '0'){
        cout<<"No\n";
        return 0;
    }
    if (s[0] == '0' && s[1] == '0'){
        cout<<"No\n";
        return 0;
    }
    if (s[n-1] == '0' && s[n-2] == '0'){
        cout<<"No\n";
        return 0;
    }
    for (int i = 1; i < n; i++)
    if (s[i] == s[i-1] && s[i] == '1'){
        cout<<"No\n";
        return 0;
    }
    int t = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            t = 0;
            continue;
        }
        t++;
        if (t > 2){
            cout<<"No\n";
        return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}