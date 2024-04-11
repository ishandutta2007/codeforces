#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5, M = 1e7 + 5;

bool ck[M];
int a[N], b[N];
int n;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ck[a[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        ck[b[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (ck[(a[i] ^ b[j])]){
                cnt++;
            }
        }
    }
    if (cnt & 1) return cout << "Koyomi", 0;
    cout << "Karen";
}