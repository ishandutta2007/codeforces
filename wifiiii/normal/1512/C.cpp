#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        string s;
        cin>>a>>b>>s;
        int ca=0,cb=0;
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i]=='?' && s[j]!='?') {
                s[i]=s[j];
            }
            if(s[i]!='?' && s[j]=='?') {
                s[j]=s[i];
            }
            ++i,--j;
        }
        i=0,j=s.size()-1;int ok=1;
        while(i<j) {
            if(s[i]!=s[j]) ok=0;
            if(s[i]!='?') {
                if(s[i]=='0') ca+=2;
                else cb+=2;
            }
            ++i,--j;
        }
        if(s.size()&1) {
            int m=s.size()/2;
            if(s[m]!='?') {
                if(s[m]=='0') ca++;
                else cb++;
            }
        }
        if(!ok || ca>a || cb>b) {
            cout<<-1<<endl;
            continue;
        }
        a-=ca,b-=cb;
        i=0,j=s.size()-1;
        if(s.size()&1) {
            int m=s.size()/2;
            if(s[m]=='?') {
                if(a&1) s[m]='0',--a;
                else {
                    assert(b&1);
                    s[m]='1',--b;
                }
            }
        }
        if(a&1 || b&1) {
            cout<<-1<<endl;
            continue;
        }
        while(i<j) {
            if(s[i]=='?') {
                assert(s[j]=='?');
                if(a) {
                    a-=2;
                    s[i]=s[j]='0';
                } else {
                    assert(b);
                    b-=2;
                    s[i]=s[j]='1';
                }
            }
            ++i,--j;
        }
        assert(!b && !a);
        cout<<s<<endl;
    }
}