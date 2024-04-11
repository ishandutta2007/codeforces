#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,a,b; cin >> n >> a >> b;
        char uwu[n+1];
        uwu[n]='\0';
        uwu[0]='a'; b--;
        for (int i=1;i<a;++i){
            if (b==0){
                uwu[i]=uwu[i-1];
            }
            else{
                uwu[i]=uwu[i-1]+1;
                b--;
            }
        }
        for (int i=a;i<n;++i){
            uwu[i]=uwu[i-a];
        }
        cout << uwu << '\n';
    }
}