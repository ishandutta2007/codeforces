#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int max =0;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int cnt =0;
    int maxLen =0;
    for(int i=0;i<n;i++){
        if(a[i]==max){
            int j = i;
            while(j<n){
                if(a[j]==a[i]){
                    j++;
                }
                else{
                    break;
                }
            }
            if(j-i > maxLen) maxLen = j-i;
            i = j;
        }
    }
    cout << maxLen << endl;
}