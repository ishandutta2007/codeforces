
 #include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        if (s[i] != '4' && s[i] != '7'){
            cout << "NO";
            return 0;
        }
        if (i < n / 2){
            sum1 += s[i] - '0';
        }
        else{
            sum2 += s[i] - '0';
        }
    }
    if (sum1 != sum2){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}