#include <bits/stdc++.h>

using namespace std;

//#define TEST

vector<long long> ctemp(101, -1);

long long c(int n){
    if(n < 2){
        return 0;
    }
    if(ctemp[n] == -1){
        ctemp[n] = 1;
        for(int i = n - 1; i <= n; i++){
            ctemp[n] *= i;
        }
        ctemp[n] /= 2;
    }
    return ctemp[n];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> count(26);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        count[temp[0] - 'a']++;
    }

    int ans = 0;

    for(int i = 0; i < 26; i++){
        if(count[i] < 2){
            continue;
        }
        int a = count[i] / 2;
        int b = count[i] - a;
        ans += c(a) + c(b);
    }

    cout << ans << "\n";
    
    return 0;
}