#include <bits/stdc++.h>

using namespace std;

int n[3];
string s;
int main(){
        cin>>s;
        int diff=0;
        for(int i=1;i<s.length();i++) if (s[i]!=s[i-1]) diff++;
        if (diff!=2){
                cout<<"NO";
                return 0;
        }
        for(int i=0,st=0;i<3;i++){
                if (s[st]!='a'+i){
                        cout<<"NO";
                        return 0;
                }
                while (st<s.length()&&s[st]=='a'+i) n[i]++,st++;
        }
        if (n[2]!=n[1]&&n[2]!=n[0]) cout<<"NO";
        else cout<<"YES";
}