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
const ll MAXN = 1000000, MOD = 1e9 + 7;
int q, qa, qaq;
int main(){
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'Q')
            q++;
        if (s[i] == 'A')
            qa += q;
        if (s[i] == 'Q')
            qaq += qa;
    }
    cout<<qaq;
    return 0;
}