#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int f[2050];
        for(int i=0;i<=2048;i++) f[i]=0;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int s;
            cin >> s;
            if(s<=2048)
            f[s]++;
        }
        for(int i=1;i<=11;i++){
            f[(1<<i)]+=(f[(1<<(i-1))]/2);
        }
        if(f[1<<11]>=1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}