#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int sum[31];
        for(int j=30;j>=0;j--){
            int temp =0;
            for(int i=0;i<n;i++){
                if((1<<j)&a[i]){
                    temp++;
                }
            }
            sum[j] = temp;
        }
        int res = 0;
        for(int j=30;j>=0;j--){
            if(sum[j]%2==0){
                continue;
            }
            else if(sum[j]%4==1){
                res = 1;
                break;
            }
            else{
                if((n-sum[j])%2==0){
                    res = -1;
                }
                else{
                    res = 1;
                }
                break;
            }
        }
        if(res==1){
            cout << "WIN" << endl;
        }
        else if(res==0){
            cout << "DRAW" << endl;
        }
        else{
            cout << "LOSE"  << endl;
        }
    }
}