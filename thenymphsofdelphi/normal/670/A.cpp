#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, b;
    cin >> n;
    m = (n / 7) * 2;
    b = n % 7;
    switch (b){
        case 0: cout << m << " " << m; return 0;
        case 1: cout << m << " " << m + 1; return 0;
        case 2: cout << m << " " << m + 2; return 0;
        case 3: cout << m << " " << m + 2; return 0;
        case 4: cout << m << " " << m + 2; return 0;
        case 5: cout << m << " " << m + 2; return 0;
        case 6: cout << m + 1 << " " << m + 2; return 0;
    }
}