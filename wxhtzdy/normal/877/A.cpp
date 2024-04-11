#include<bits/stdc++.h>
using namespace std;
string f[5]={"Danil","Olya","Slava","Ann","Nikita"};
int main(){
    string s;
    cin>>s;
    int n=(int)s.length(),cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(n-i<(int)f[j].length())continue;
            bool ok=1;
            for(int k=0;k<(int)f[j].length();k++){
                if(f[j][k]!=s[i+k])ok=0;
            }
            if(ok)cnt++;
        }
    }
    if(cnt==1)printf("YES");
    else printf("NO");
}