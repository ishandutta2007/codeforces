#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair <int, int> a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    int mx = -1;
    for (int i = 0; i < n; i++){
        if (mx <= a[i].second){
        	mx = a[i].second;
        }
        else{
         	mx = a[i].first;
        }
    }
    cout << mx;
}