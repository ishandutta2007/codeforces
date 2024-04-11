#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    bool issum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != 1){
                issum = false;
                for (int k = 0; k < n; k++){
                    for (int l = 0; l < n; l++){
                        if (a[i][l] + a[k][j] == a[i][j]){
                            issum = true;
                            break;
                        }
                    }
                }
                if (!issum){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}