#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin >> N;
    string s;
    cin >> s;
    int changes = 0;
    

    for(int i = 0; i < N; i+=2) {
        char a = s[i];
        char b = s[i+1];

        if(a == b) {
            ++changes;
            if(a == 'a') {
                s[i]='b';
            } else {
                s[i]='a';
            }
        }


    }
    cout << changes << "\n";
    cout << s << "\n";
}