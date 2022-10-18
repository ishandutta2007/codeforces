#include<bits/stdc++.h>
using namespace std;

vector <int> a;

bool isprime(int n){
    if (n <= 1){
        return 0;
    }
    if (n <= 3){
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0){
            return 0;
        }
    }
    for (int i = 7; i * i <= n; i += 6){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, t;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (isprime(i)){
            t = i;
            while (t <= n){
                a.push_back(t);
                t *= i;
            }
        }
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
}