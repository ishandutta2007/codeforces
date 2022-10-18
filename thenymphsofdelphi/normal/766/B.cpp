#include<bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c){
    int tmp[] = {a, b, c};
    sort(tmp, tmp + 3);
    return (tmp[0] + tmp[1] > tmp[2]);
}

int main(){
    int n;
    cin >> n;
    if (n >= 45){
        cout << "YES";
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        for (int x = i + 1; x < n; x++){
            for (int j = x + 1; j < n; j++){
                if (check(arr[i], arr[x], arr[j])){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}