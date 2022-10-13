#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t = 1;
    while(t--){
        bool inf = false;
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int cnt =0;
        for(int i=0;i<n-1 && !inf;i++){
            if((a[i]==2 && a[i+1]==3) || (a[i]==3 && a[i+1]==2)){
                inf = true; 
            }
            if(a[i]==1 && a[i+1]==3){
                cnt+=4;
            }
            if(a[i]==3 && a[i+1]==1){
                cnt+=4;
            }
            if(a[i]==2 && a[i+1]==1){
                cnt+=3;
            }
            if(a[i]==1 && a[i+1]==2){
                cnt+=3;
            }
            
        }
        for(int i=0;i<n-2;i++){
            if(a[i]==3 && a[i+1]==1 && a[i+2]==2){
                cnt--;
            }
        }
        if(inf){
            cout << "Infinite" << endl;
            continue;
        }
        cout << "Finite" << endl;
        cout << cnt << endl;
    }
}