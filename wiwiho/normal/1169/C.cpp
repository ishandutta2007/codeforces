#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = -1;
    int r = m;
    while(l < r - 1){
        int mid = (l + r) / 2;
        int last = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(a[i] + mid < last){
                flag = true;
                break;
            }
            if(a[i] >= last && (a[i] + mid < m || (a[i] + mid) % m < last)){
                last = a[i];
            }
        }
        if(flag){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << r << "\n";
    
    return 0;
}