#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    int a = -1, b = -1;
    for(int i = 5; i * i <= k; i++){
        if(k % i == 0 && k / i >= 5){
            a = i;
            b = k / i;
            break;
        }
    }

    if(a == -1){
        cout << "-1\n";
        return 0;
    }

    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

    for(int i = 0; i < b; i++){
        if(i < 5){
            for(int j = i; j < i + 5; j++){
                cout << vowel[j % 5];
            }
            for(int j = 5; j < a; j++){
                cout << vowel[i % 5];
            }
        }
        else{
            for(int j = 0; j < a; j++){
                cout << vowel[j % 5];
            }
        }
    }
    cout << "\n";
    
    return 0;
}