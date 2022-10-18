#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i, j, iii, jjj, ans;
    int a[5][5];
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                iii = i;
                jjj = j;
            }
        }
    }
    ans = abs(iii - 2) + abs(jjj - 2);
    cout << ans;
}