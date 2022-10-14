#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n=(int)s.length();
        int x=n+1,y=0,sum=0;
        for(int i=0; i<n; ++i) {
            if(s[i]=='1')
                x=min(x,i),y=max(y,i),++sum;
        }
        cout << max(0, y-x+1)-sum << "\n";
    }
    return 0;
}