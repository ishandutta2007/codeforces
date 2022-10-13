#include <bits/stdc++.h>
using namespace std;

string refer = "abcdefghijklmnopqrstuvwxyz";
string generateRandom(int len){
    string ret = "";
    for(int i=0;i<len;i++){
        ret+=refer[rand()%26];
    }
    return ret;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        string x[n+1];
        x[0] = generateRandom(100);
        for(int i=1;i<n+1;i++){
            x[i] = x[i-1].substr(0,a[i-1])+refer[(x[i-1][a[i-1]]-'a'+1)%26]+generateRandom(100-a[i-1]-1);   
        }
        for(int i=0;i<n+1;i++){
            cout << x[i] << endl;
        }

    }

}