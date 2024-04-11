#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n>=8) {
            pair<int,int> ans;
            for(int i=0;i<=n;i++) {
                if(5*i<=n && (n-5*i)%3==0) {
                    ans = {(n-5*i)/3,i};
                }
            }
            cout << ans.first << " " << ans.second << " " << 0 << endl;
        }
        else {
            tuple<int,int,int> ans = {-1,-1,-1};
            for(int a=0;a<=2;a++) {
                for(int b=0;b<=2;b++) {
                    for(int c=0;c<=2;c++) {
                        if(3*a+5*b+7*c==n) {
                            ans = {a,b,c};
                        }
                    }
                }
            }
            if(get<0>(ans)<0) cout << -1 << endl;
            else
                cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;
        }
    }
}