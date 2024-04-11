#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    switch (n){
        case 2: return true;
        case 3: return true;
        case 5: return true;
        case 7: return true;
        case 11: return true;
        case 13: return true;
        case 17: return true;
        case 19: return true;
        case 23: return true;
        case 29: return true;
        case 31: return true;
        case 37: return true;
        case 41: return true;
        case 43: return true;
        case 47: return true;
        default: return false;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if (!isprime(m)){
        cout << "NO";
        return 0;
    }
    for (int i = n + 1; i < m; i++){
        if (isprime(i)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}