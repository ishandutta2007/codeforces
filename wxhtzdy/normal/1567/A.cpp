#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ff(i,0,n-1){
        if(s[i] == 'U')s[i] = 'D';
        else if(s[i] == 'D')s[i] = 'U';
    }
    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}