#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int posSum = 0;
        int negSum = 0;
        for(int i=0;i<n;i++){
            if(a[i]>0) posSum+=a[i];
            else negSum+=a[i];
        }
        if(posSum==abs(negSum)) cout << "NO" << endl;
        else {
            if(posSum>abs(negSum)) {
                sort(a,a+n,greater<int>());
            }
            else{
                sort(a,a+n);
            }
            bool work = true;
            int sum = 0;
            for(int i=0;i<n;i++) {
                sum+=a[i];
                if(sum==0) work = false;
            }
            if(!work) cout << "NO" << endl;
            else {
            cout << "YES" << endl;
            for(int i=0;i<n;i++) cout << a[i] << " ";
            cout << endl;
            }
        }
    }
}