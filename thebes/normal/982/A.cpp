#include <bits/stdc++.h>
using namespace std;

int N, flag, i;
string s;

int main(){
    cin >> N >> s;
    for(i=1;i<s.size();i++){
        if(s[i]=='1'&&s[i-1]=='1'){
            printf("NO\n");
            return 0;
        }
    }
    for(i=0;i<s.size();i++){
        if(s[i]=='1') continue;
        bool w1=0, w2=0;
        if(!i||s[i-1]=='0') w1=1;
        if(i==s.size()-1||s[i+1]=='0') w2=1;
        if(w1&&w2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}