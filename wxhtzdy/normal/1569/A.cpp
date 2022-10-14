#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;




void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ff(i,0,n-1){
        map<char, int> slovo;
        ff(j,i,n-1){
            slovo[s[j]]++;
            if(slovo['a'] == slovo['b']){
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n"; //glupi kejs
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}