#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const string dict="fedabc";
int convert(char ch){
    int ans=0;
    while (dict[ans]!=ch) ans++;
    return ans;
}
int n;
string s;
ull reach(ull cur){
    if (cur&1) {
        cur>>=2;
        return cur*16;
    }
    return 7+reach(cur-1);
}
ull solve(ull pos,char ch){
    return reach(pos)+convert(ch)+1;
}
int main(){
    cin>>s;
    int n=s.length();
    char type=s[n-1];
    ull pos=0;
    for(int i=0;i<n-1;i++) pos=10*pos+(s[i]-'0');
    cout<<solve(pos,type);
}