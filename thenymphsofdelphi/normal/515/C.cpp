#include<bits/stdc++.h>
using namespace std;

string ch[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};

int main(){
    int n;
    cin >> n;
    string str, an;
    cin >> str;
    for (int i = 0; i < str.size(); i++){
        an += ch[str[i] - '0'];
    }
    sort(an.begin(), an.end());
    reverse(an.begin(), an.end());
    cout << an << endl;
    return 0;
}