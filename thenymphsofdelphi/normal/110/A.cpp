#include<iostream>
using namespace std;

int main(){
    unsigned long long n;
    int i, cnt = 0;
    cin >> n;
    while (n != 0){
        if (n % 10 == 4 || n % 10 == 7){
            cnt++;
        }
        n /= 10;
    }
    if (cnt == 4 || cnt == 7){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}