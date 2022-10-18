#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        switch (i % 4){
            case 0: cout << 'a'; break;
            case 1: cout << 'a'; break;
            case 2: cout << 'b'; break;
            case 3: cout << 'b'; break;
        }
    }
}