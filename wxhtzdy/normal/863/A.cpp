#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=(int)s.length(),j=-1;
    for(int i=n-1;i>=0;i--)if(s[i]!='0'){j=i;break;}
    for(int i=0;i<=j;i++){
        if(s[i]!=s[j-i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}