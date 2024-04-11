#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool f1;
int f2;
int sum=0;
int main(){
    cin>>n;
    while (n--){
        sum=f1=f2=0;
        cin>>s;
        for (int i=0;i<s.size();++i){
            if (s[i]=='0') f1=1;
            if ((s[i]-'0')%2==0) f2++;
            sum+=s[i]-'0';
        }
        if (sum%3==0&&f1&&f2>1) cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
    return 0;
}