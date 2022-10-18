#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

const int N = 26;

int n, l, val;
string s;
bool ck1[N], ck2[N * N];

int main(){
    cin >> n;
    while (n--){
        cin >> s;
        l = s.length();
        for (int i = 0; i < l; i++){
            val = s[i] - 'a';
            ck1[val] = 1;
        }
        for (int i = 1; i < l; i++){
            val = (s[i - 1] - 'a') * N + (s[i] - 'a');
            ck2[val] = 1;
        }
    }
    for (int i = 0; i < N; i++){
        if (!ck1[i]){
            cout << (char)(i + 'a');
            return 0;
        }
    }
    for (int i = 0; i < N * N; i++){
        if (!ck2[i]){
            cout << (char)(i / N + 'a');
            i %= N;
            cout << (char)(i + 'a');
            return 0;
        }
    }
}