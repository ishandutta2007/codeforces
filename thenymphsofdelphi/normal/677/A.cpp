#include<iostream>
using namespace std;

int main(){
    int n, h, i;
    cin >> n >> h;
    int x, count = n;
    for (i = 0; i < n; i++){
        cin >> x;
        if (x > h){
            count++;
        }
    }
    cout << count;
}