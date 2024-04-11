#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        string s;
        cin >> n >> s;

        int curr = 0;
        int ans =0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                curr--;
            }
            else{
                curr++;

            }
            if(curr<0){
                ans++;
                curr = 0;

            }
        }
        cout << ans << endl;
    }
}