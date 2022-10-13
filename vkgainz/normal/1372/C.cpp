#include <bits/stdc++.h>
using namespace std;
int n;

void solve(int a[]){
    int fir = n+1;
    int las = -1;
    for(int i=0;i<n;i++){
        if(a[i]!=(i+1)){
            fir = min(fir,i);
            las = max(las,i);
        }
    }
    if(fir==n+1 && las==-1){
        cout << 0 << endl;
    }
    else{
        int num =0;
        for(int i=fir;i<=las;i++){
            if(a[i]!=(i+1)){
                num++;
            }
        }
        if(num==(las-fir+1)){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    solve(a);
    }
}