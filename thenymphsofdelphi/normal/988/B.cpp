#include<bits/stdc++.h>
using namespace std;

void sort(string s[], int n){
    for (int i = 1; i < n; i++){
        string temp = s[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length()){
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

bool issubstring(string a, string b){
    if (a.find(b) != string::npos) return 1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, n);
    for (int i = 1; i < n; i++){
        if (!issubstring(a[i], a[i-1])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << endl;
}