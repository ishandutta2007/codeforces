#include<iostream>
using namespace std;

int main(){
    int a[11][11];
	int n, m, i, j, cnt = 0;
    bool ck = false;
    cin >> n >> m;
    string s;
    for (i = 0; i < n; i++){
    	cin >> s;
        for (j = 0; j < m; j++){
            if (s[j] == '.'){
            	a[i][j] = 0;
			}
			else{
				a[i][j] = 1;
			}
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (a[i][j] == 1){
                ck = true;
            }
        }
        if (ck == false){
            for (j = 0; j < m; j++){
                a[i][j] = -1;
        	}
        }
        ck = false;
    }
    for (j = 0; j < m; j++){
        for (i = 0; i < n; i++){
            if (a[i][j] == 1){
                ck = true;
            }
        }
        if (ck == false){
            for (i = 0; i < n; i++){
                a[i][j] = -1;
        	}
        }
        ck = false;
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (a[i][j] == -1){
                cnt++;
            }
        }
    }
    cout << cnt;
}