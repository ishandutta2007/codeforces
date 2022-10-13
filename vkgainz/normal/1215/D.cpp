#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dig[n];
    string s; cin >> s;
    int numF = 0;
    int totF =0;
    int numL = 0;
    int totL = 0;
    for(int i=0;i<n;i++){
        if(i<n/2){
            if(s[i]=='?') numF++;
            else totF+=(s[i]-'0');
        }
        else{
            if(s[i]=='?') numL++;
            else totL+=(s[i]-'0');
        }
    }
    int dif = numF-numL;
    if(dif<0) totL-=9*dif/2;
    else totF+=9*dif/2;
    if(totF==totL) cout << "Bicarp" << endl;
    else cout << "Monocarp" << endl;
    
}