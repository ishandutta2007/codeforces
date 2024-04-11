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
const int N = 1e5 + 7;
string F (string s){
    for (int i = 0; i < s.size(); i++){
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += 'a' - 'A';
        if (s[i] == 'o')
            s[i] = '0';
        if (s[i] == 'i' || s[i] == 'l')
            s[i] = '1';
    }
    return s;
}
int main()
{
    string S;
    cin>>S;
    S = F(S);
    int Q;
    cin>>Q;
    while (Q--){
        string s;
        cin>>s;
        s = F(s);
        if (S == s){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}