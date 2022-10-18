#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, i, temp = 1, maximum = 0;
    long a[100000];
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (i >= 1){
            if (a[i] >= a[i - 1]){
                temp++;
            }
            else{
                maximum = max(maximum, temp);
                temp = 1;
            }
        }
    }
    maximum = max(maximum, temp);
    cout << maximum;
}