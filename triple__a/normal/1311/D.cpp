#include<bits/stdc++.h>
using namespace std;

int t,a,b,c,A,B,C,val;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        A = B = C = -1, val=-1;
        for (int i = 1; i <= 1e4;++i){
            for (int j = i; j <= 2e4;j+=i){
                for (int k = j; k <= 2e4;k+=j){
                    if (A==-1||abs(i-a)+abs(j-b)+abs(k-c)<val){
                        val = abs(i - a) + abs(j - b) + abs(k - c);
                        A = i, B = j, C = k;
                    }
                }
            }
        }
        cout << val << endl;
        cout << A << " " << B << " " << C << endl;
    }
    return 0;
}