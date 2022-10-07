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
int T, ans, p;
int a[26], b[26];
int main() {
    cin>>T;
    for (int I = 0; I < T; I++){
        int num = 0;
        for (int i = 0; i < 26; i++)
            if (a[i] == I)
                num++;
        p = 0;
        if (num == 1 && I < T - 1)
            p = 1;
        char ch;
        string s;
        cin>>ch>>s;
        if (ch != '.' && I < T - 1)
            ans += p;
        if (ch == '.' || ch == '?'){
            for (int i = 0; i < 26; i++)
                b[i] = 1;
            for (int i = 0; i < s.size(); i++)
                b[s[i] - 'a'] = 0;
        }
        else {
            for (int i = 0; i < 26; i++)
                b[i] = 0;
            for (int i = 0; i < s.size(); i++)
                b[s[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++)
            a[i] += b[i];
    }
    cout<<ans<<endl;
    return 0;
}