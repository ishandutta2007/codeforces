#include<iostream>
using namespace std;

int main(){
    long n, k;
    while (cin >> n >> k){
        long sum = 0, a = 0;
        do {
            sum += n;
            a %= k;
            a += n;
            n = a/k;
        } while (a >= k);
        cout << sum << endl;
	}
}