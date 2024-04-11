#include<algorithm>
#include<iostream>
using namespace std; 

int main(){
    long a[4], i;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    int count = 0;
    for (i = 1; i < 4; i++){
        if (a[i] == a[i - 1]){
            count++;
        }
    }
    cout << count;
}