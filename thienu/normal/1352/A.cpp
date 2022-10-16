#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve(){
    string in;
    cin >> in;
    int n = in.size();
    int cnt = 0;
    vector<string> out;
    for(int i = 0; i < n; i++){
        if(in[i] != '0'){
            cnt++;
            string s = string(1, in[i]);
            for(int j = i+1; j < n; j++){
                s += "0";
            }
            out.push_back(s);
        }
    }
    printf("%d\n", cnt);
    for(string s : out){
        cout << s << " ";
    }
    printf("\n");
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}