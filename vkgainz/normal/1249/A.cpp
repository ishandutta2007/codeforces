#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        int num = 1;
        int color[n];
        for(int i=0;i<n;i++) color[i] = 0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1){
                num = 2;
            }
        }
        cout << num << endl;
    }
}