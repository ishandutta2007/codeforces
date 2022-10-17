#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define ld long double

ld wylosoj_dobre(int good, int bad, int at_least, int to_go){
    if(at_least == 0)
        return 1.0;

    if(to_go == 0)
        return 0.0;

    if(good == 0)
        return 0.0;

    if(bad == 0)
        return 1.0;

    return (good / (ld)(good + bad)) * wylosoj_dobre(good - 1, bad, at_least - 1, to_go - 1) +
           (bad / (ld)(good + bad)) * wylosoj_dobre(good, bad - 1, at_least, to_go - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ld p;
    cin >> p;

    for(int i = 0; i < n; i++){
        if((wylosoj_dobre(i, n - i, 1, 3) + wylosoj_dobre(i, n - i, 2, 3)) / 2.0 + 1e-10 >= p){
            cout << i << '\n';
            return 0;
        }
    }
    assert(false);
}