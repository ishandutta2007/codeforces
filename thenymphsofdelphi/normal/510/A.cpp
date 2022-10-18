#include<iostream>
using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (i % 2 == 0){
                cout << "#";
            }
            else if ((i % 4 == 1 && j == m - 1) || (i % 4 == 3 && j == 0)){
                cout << "#";
            }
            else{
                cout << ".";
            }
        }
        cout << endl;
    }
}