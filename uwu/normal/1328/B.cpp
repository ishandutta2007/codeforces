#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    for (int q=0;q<t;++q){
        int n,k; cin >> n >> k;
        int pos1;
        for (int i=1;i<=100000;++i){
            if (k<=i){
                pos1=n-i-1;
                break;
            }
            k-=i;
        }
        int pos2=n-k;
        char arr[n];
        for (int i=0;i<n;++i){
            arr[i]='a';
        }
        arr[pos1]='b';
        arr[pos2]='b';
        for (int i=0;i<n;++i){
            cout << arr[i];
        }
        cout << '\n';

    }
}