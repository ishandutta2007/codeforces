#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int numR =0;
        int numS =0;
        int numP =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                numR++;
            }
            else if(s[i]=='S'){
                numS++;
            }
            else{
                numP++;
            }
        }
        int most = max(numR,max(numS,numP));
        string ret;
        if(most==numR){
            
            for(int i=0;i<n;i++){
                ret+='P';
            }
        }
        else if(most==numS){
            for(int i=0;i<n;i++){
                ret+='R';
            }
        }
        else{
            for(int i=0;i<n;i++){
                ret+='S';
            }
        }
        cout << ret << endl;
    }
}