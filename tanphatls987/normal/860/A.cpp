#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=2e5+10;
const int maxv=1e6+10;
const string wowel="aeiou";


bool check(char ch){
    for(auto i:wowel) if (i==ch) return 1;
    return 0;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    for(int en=0,st=0,diff=0;en<n;en++){
        if (check(s[en])){
            st=en+1;
            diff=0;
        }else{
            if (s[en]!=s[st]) diff=1;
            if (en-st>=2&&diff){
                cout<<' ';
                diff=0;
                st=en;
            }
        }
        cout<<s[en];
    }
}