#include <bits/stdc++.h>
using namespace std;

int t,n,x;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n, greater<int>());
        int numTeam =0;
        int min;
        int l =0; int r =0;
        long long temp = 0;
        while(r<n){
            min = a[l];
            while(r<n){
                temp = (long long) a[r]*(r-l+1);
                if(temp>=x){
                    numTeam++;
                    break;
                }
                else{
                    r++;
                }
                
            }
            l = r;
            l++;
            r++;
        }
        cout << numTeam << endl;
    }
}