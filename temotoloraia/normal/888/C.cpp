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
int mas[26];
int a[26];
int ans;
int main()
{
    string s;
    cin>>s;
    for (int i = 1; i <= (int)s.size(); i++){
        char ch = s[i - 1];
        a[ch - 'a'] = max (a[ch - 'a'], i - mas[ch - 'a']);
        mas[ch - 'a'] = i;
    }
    ans = s.size();
    for (int i = 0; i < 26; i++)
        ans = min (ans, max (a[i], (int)s.size() + 1 - mas[i]));
    cout<<ans<<endl;
    return 0;
}