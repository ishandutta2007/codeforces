#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length(), a[4], b[4];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++){
        if (s[i] != '!'){
            switch (s[i]){
                case 'R': a[0] = i % 4; break;
                case 'B': a[1] = i % 4; break;
                case 'Y': a[2] = i % 4; break;
                case 'G': a[3] = i % 4; break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (s[i] == '!'){
            int val;
            for (int j = 0; j < 4; j++){
                if (a[j] == i % 4){
                    val = j;
                    break;
                }
            }
            b[val]++;
        }
    }
    for (int i = 0; i < 4; i++){
        cout << b[i] << ' ';
    }
}