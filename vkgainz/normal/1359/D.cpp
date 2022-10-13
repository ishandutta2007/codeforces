#include <bits/stdc++.h>
using namespace std;


int n;
int maxSum(int x[],int num){
    int l = 0;
    int r =0;
    int best =0;
    while(r<n){
        int tempSum =0;
        while(r<n){
            if(x[r]>num){
                break;
            }
            else{
                tempSum+=x[r];
                if(tempSum<=0){
                    break;
                }
                else{
                    best = max(best,tempSum);
                    r++;
                }
            }
        }
        l = r;
        r++;
        l++;
    }
    return best-num;
}
int main(){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0;i<=30;i++){
        ans = max(ans,maxSum(a,i));
    }
    cout << ans << endl;
}