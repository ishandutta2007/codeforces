#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int x = 0;
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            if(x%2) a[i] = (a[i]-1)/2;
            else a[i] = (a[i]+1)/2;
            ++x;
        }
        else{
            a[i]/=2;
        }
    }
    for(int i=0;i<n;i++) cout << a[i] << endl;
}