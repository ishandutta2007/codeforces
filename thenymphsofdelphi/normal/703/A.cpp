#include<iostream>
using namespace std;

int main(){
    int n, a = 0, b = 0, x, y;
    cin >> n;
    while (n--){
        cin >> x >> y;
        if (x > y) a++;
        if (y > x) b++;
    }
    if (a > b) cout << "Mishka";
    else if (b > a) cout << "Chris";
    else cout << "Friendship is magic!^^";
}