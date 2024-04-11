#include <bits/stdc++.h>
using namespace std;

string s, t;

int main(){
    cin >> s >> t;
    if(s.size()!=t.size()) printf("No\n");
    else{
        for(int i=0;i<s.size();i++){
            bool a=0, b=0;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') a=1;
            if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u') b=1;
            if(a!=b){
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
}