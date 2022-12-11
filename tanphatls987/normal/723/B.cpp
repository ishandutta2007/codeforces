#include <bits/stdc++.h>

using namespace std;

int n,h[300];
string s;
stack <int> st;


bool ischar(char ch){
    if ('a'<=ch&&ch<='z') return 1;
    if ('A'<=ch&&ch<='Z') return 1;
    return 0;
}
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++) {
        if (s[i]=='(') st.push(i);
        if (s[i]==')'){
            h[st.top()]++;
            h[i+1]--;
            st.pop();
        }
    }
    int ansl=0,ansn=0;
    for(int i=1;i<n;i++) h[i]+=h[i-1];
    for(int i=0;i<n;i++) if (ischar(s[i])){
        int len=0;
        while (i+len<n&&ischar(s[i+len])) len++;
        if (h[i]) ansn++;
        else ansl=max(ansl,len);
        i+=len;
//        cout<<i<<" "<<len<<'\n';
    }
    cout<<ansl<<" "<<ansn;
}