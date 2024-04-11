#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string a="",b="";
        bool ok=1;
        for(int i=0;i<n;i++){
            if(ok){
                if(s[i]=='2'){
                    a+='1';
                    b+='1';
                }else if(s[i]=='0'){
                    a+='0';
                    b+='0';
                }else{
                    a+='1';
                    b+='0';
                    ok=0;
                }
            }else{
                b+=s[i];
                a+='0';
            }
        }
        cout<<a<<'\n'<<b<<'\n';
    }
    return 0;
}