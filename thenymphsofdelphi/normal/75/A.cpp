#include<bits/stdc++.h>
using namespace std;

long long cnv(long long n){
    long long ans = 0, pw = 0;
    while (n != 0){
        if (n % 10 != 0){
            ans += pow(10, pw) * (n % 10);
            pw++;
        }
        n /= 10;
    }
    return ans;
}

int main(){
    long long a, b, c;
    cin >> a >> b;
    c = a + b;
    a = cnv(a);
    b = cnv(b);
    c = cnv(c);
    if (a + b == c){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}