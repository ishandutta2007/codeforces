#include<iostream>
using namespace std;

int main(){
    long long n, m, y, x = 1, count = 0, i;
    cin >> n >> m;
    for (i = 0; i < m; i++){
        cin >> y;
        if (y >= x){
            count += y - x;
        }
        else{
            count += y + n - x;
        }
        x = y;
    }
    cout << count;
}