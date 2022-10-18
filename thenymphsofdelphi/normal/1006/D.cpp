/*
    Author: Sola Stunfell (**tranxuanbach**)
    Date: 16/07/2018
    Time: 23:19 (UTC + 7)
*/
#include<bits/stdc++.h>
using namespace std;
#define push_back pb
#define pop_back pob
#define make_pair mp
#define endl "\n"
using namespace std;

int changes(char a, char b, char c, char d){
    if (a == c && b == d){
        return 0;
    }
    if (a == c && b != d){
        return 1;
    }
    if (a != c && b == d){
        return 1;
    }
    
    swap(a, b);
    if (a == c && b == d){
        return 0;
    }
    if (a == c && b != d){
        return 1;
    }
    if (a != c && b == d){
        return 1;
    }
    
    if (a == b && c == d){
        return 0;
    }
    if (a == b && c != d){
        return 2;
    }
    if (a != b && c == d){
        return 1;
    }
    return 2;
}

signed main(){
    int n, ans = 0;
    string a, b;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n / 2; i++){
        ans += changes(a[i], a[n - i - 1], b[i], b[n - i - 1]);
    }
    if (n % 2){
        if (a[(n - 1) / 2] != b[(n - 1) / 2]){
            ans++;
        }
    }
    cout << ans << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}