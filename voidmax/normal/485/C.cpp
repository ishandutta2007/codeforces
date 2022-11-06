#include <iostream>
#define int long long
using namespace std;


int a, b, n, counter;

int near(int b) {
    int a = 1;
    while (a <= b) {
        a *= 2;
    }
    return a / 2;
}

int ans(int &a, int &b) {
    int f = a, k = b;
    bool arr1[201];
    bool arr2[201];
    bool arr3[201];
    for (int i = 0; i < 201; ++i) {
        arr1[i] = arr2[i] = arr3[i] = false;
    }
    int counter = 0;
    //cout << a << ' ' << b << endl;
    for (int i = 0; a != 0; ++i) {
        arr1[i] = a % 2;
        counter += arr1[i];
        a /= 2;
        //cout << arr1[i];
    }
    //cout << endl;
    int index = 0;
    for (index = 0; index < 201; ++index) {
        if (!arr1[index]) {
            if (index == counter) {
                return f;
            }
            break;
        }
    }
    for (int i = 0; b != 0; ++i) {
        arr2[i] = b % 2;
        //cout << arr2[i];
        b /= 2;
    }
    //cout << endl;
    for (int i = 200; i > -1; --i) {
        //cout << i << endl;
        if (arr2[i] != arr1[i]) {
            arr3[i] = true;
            for(int q = i - 1; q > -1; --q) {
                if (!arr1[q]) {
                    arr3[i] = false;
                    break;
                }
            }
            for(int q = i - 1; q > -1; --q) {
                arr3[q] = true;
            }
            i = -300;
        }
        else {
            arr3[i] = arr2[i];
        }
    }
    int answer = 0;
    //cout << endl;
    for (int i = 200; i > -1; --i) {
        //cout << arr3[i];
        answer *= 2;
        answer += (int)arr3[i];
        //cout << arr3[i];
    }
    //cout << endl;
    return answer;
}

main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << ans(b, a) << endl;
    }
}