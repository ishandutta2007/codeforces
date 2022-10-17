#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r,c; cin >> r >> c;
        bool arr[r][c]; //black is false, white is true
        bool temp=true;
        for (int i=0;i<r;++i){
            for (int k=0;k<c;++k){
                temp=!temp;
                arr[i][k]=temp;
            }
        }
        if ((c*r)%2==0){
            if (c%2==0){
                arr[r-1][1]=false;
            }
            if (c%2==1){
                arr[r-1][0]=false;
            }
        }
        for (int i=0;i<r;++i){
            for (int k=0;k<c;++k){
                if (arr[i][k]) cout << "W";
                else cout << "B";
            }
            cout << '\n';
        }
        
    }
}