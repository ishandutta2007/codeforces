#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=(int)s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(int)(s[i]-'0');
        }
        if(sum%3!=0){
            cout<<"cyan"<<'\n';
            continue;
        }
        int cnt=0,k=0;
        for(int i=0;i<n;i++){
            int dgt=(int)(s[i]-'0');
            if(dgt==0)cnt++;
            else if(dgt%2==0)k++;
        }
        if(cnt>0&&(cnt>1||k>0))cout<<"red"<<'\n';
        else cout<<"cyan"<<'\n';
    }
    return 0;
}