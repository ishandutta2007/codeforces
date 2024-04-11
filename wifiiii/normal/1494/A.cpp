#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        int ok=0;
        for(int i='(';i<=')';++i)
            for(int j='(';j<=')';++j)
                for(int k='(';k<=')';++k) {
                    string t=s;
                    for(char &c : t) {
                        if(c=='A') c=i;
                        if(c=='B') c=j;
                        if(c=='C') c=k;
                    }
                    int cnt=0,okk=1;
                    for(char c:t) {
                        if(c=='(') ++cnt;
                        else --cnt;
                        if(cnt<0) okk=0;
                    }
                    if(cnt) okk=0;
                    if(okk) ok=1;
                }
        cout<<(ok?"YES":"NO")<<'\n';
    }
}