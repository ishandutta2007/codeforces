#include <bits/stdc++.h>

using namespace std;

const int alp=26;
int h[alp];
int main(){
        int test;
        cin>>test;
        for(int i=0;i<alp;i++) h[i]=1;
        int ans=0;
        for(int i=1;i<test;i++){
                char type;
                string s;
                cin>>type>>s;
                if (type!='.'&&count(h,h+alp,1)==1) ans++;
                int mask=0;
                for(int i=0;i<s.length();i++) mask|=1<<(s[i]-'a');
                if (type=='!') mask^=(1<<alp)-1;
                for(int i=0;i<alp;i++) if (mask&(1<<i)) h[i]=0;
        }
        cout<<ans;
}