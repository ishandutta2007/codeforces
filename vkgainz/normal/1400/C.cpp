#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int x; cin >> x;
        int dig[s.length()];
        for(int i=0;i<s.length();i++) dig[i] = 1;
        bool work = true;
        for(int i=0;i<s.length() && work;i++){
            if(s[i]=='0'){
                if(i-x>=0){
                    dig[i-x]= 0;
                }
                if(i+x<s.length()){
                    dig[i+x] = 0;
                }
            }
        }
        for(int i=0;i<s.length() && work;i++){
            if(s[i]=='1'){
                int cnt =0;
                if(((i-x>=0 && dig[i-x]==0) || (i-x<0)) && ((i+x<s.length() && dig[i+x]==0) || (i+x>=s.length()))){
                    work = false;
                }
            }
        }
        if(work){
            string t;
            for(int i=0;i<s.length();i++) t+=to_string(dig[i]);
            cout << t << endl;
        }
        else{
            cout << -1 << endl;

        }

    }
}