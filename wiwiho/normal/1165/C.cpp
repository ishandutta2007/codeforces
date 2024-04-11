#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    char last;
    bool odd = true;
    string result;
    for(int i = 0; i < n; i++){
        if(odd){
            result += s[i];
            last = s[i];
            odd = false;
        }
        else{
            if(s[i] != last){
                result += s[i];
                odd = true;
            }
            else{
                ans++;
            }
        }
    }

    if(result.length() % 2 == 1){
        ans++;
        result.erase(result.length() - 1);
    }

    cout << ans << "\n" << result << "\n";
    
    return 0;
}