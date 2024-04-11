#include<bits/stdc++.h>
using namespace std;

int a[10][10], b[10][10];
int n;

void rotate(){
    int k, l;
    if (n & 1){
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2 + 1; j++){
                k = n - 1 - i;
                l = n - 1 - j;
                swap(a[i][j], a[j][k]);
                swap(a[j][k], a[k][l]);
                swap(a[k][l], a[l][i]);
            }
        }
    }
    else{
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++){
                k = n - 1 - i;
                l = n - 1 - j;
                swap(a[i][j], a[j][k]);
                swap(a[j][k], a[k][l]);
                swap(a[k][l], a[l][i]);
            }
        }
    }
    return;
}

void flip(){
    int k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n / 2; j++){
            k = n - 1 - j;
            swap(a[i][j], a[i][k]);
        }
    }
    return;
}


void ck(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != b[i][j]){
                return;
            }
        }
    }
    cout << "Yes";
    exit(0);
}

int main(){
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < n; j++){
            a[i][j] = (s[j] == 'X' ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < n; j++){
            b[i][j] = (s[j] == 'X' ? 1 : 0);
        }
    }
    ck();
    rotate();
    ck();
    rotate();
    ck();
    rotate();
    ck();
    rotate();
    flip();
    ck();
    rotate();
    ck();
    rotate();
    ck();
    rotate();
    ck();
    rotate();
    cout << "No";
}