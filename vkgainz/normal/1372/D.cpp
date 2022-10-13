#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long best =0;
    long long fir =0;
    long long sec =0;
    for(int i=0;i<n;i+=2){
        fir+=a[i];
    }
    for(int i=1;i<n;i+=2){
        sec+=a[i];
    }
    sec+=a[0];
    best = max(fir,sec);
    for(int i=2;i<n;i++){
        if(i%2==0){
            fir-=a[i-2];
            fir+=a[i-1];
        }
        else{
            sec-=a[i-2];
            sec+=a[i-1];
        }
        best = max(best,fir);
        best= max(best,sec);
    }
    cout << best << endl;
}