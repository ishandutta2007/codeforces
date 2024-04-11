#include <bits/stdc++.h>
using namespace std;
int n,k;
int s[200001];
int main(){
    cin >> n >> k;
    string a;
    cin >> a;
    for(int i=0;i<n;i++){
        s[i] = 1000000000;
    }
    vector<int> x;
    for(int i=0;i<n;i++){
        if(a[i]==a[(i+1)%n] || a[i]==a[(i+n-1)%n]){
            x.push_back(i);
        }
    }
    string ret = "";
    if(x.size()==0){
        if(k%2){
            for(int i=0;i<n;i++){
                (a[i]=='W') ? ret+="B":ret+="W";
            }

        }
        else{
            ret = a;
        }
        cout << ret << endl;
        return 0;
    }
    int l = x[x.size()-1]-n;
    int idx =0;
    for(int i=0;i<n;i++){
        if(idx<x.size() && x[idx] == i){
            l = x[idx];
            idx++;
        }
        s[i] = min(s[i],i-l);
    }
    int r = x[0]+n;
    idx = x.size()-1;
    for(int i=n-1;i>=0;i--){
        if(idx>=0 && x[idx] == i){
            r = x[idx];
            idx--;
        }
        s[i] = min(s[i],r-i);
    }
    for(int i=0;i<n;i++){
        int add = min(s[i],k);
        if(a[i]=='W'){
            if(add%2){
                ret+="B";
            }
            else{
                ret+="W";
            }
        }
        else{
            if(add%2){
                ret+="W";
            }
            else{
                ret+="B";
            }
        }
    }
    cout << ret << endl;
    
    
    
}