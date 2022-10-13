#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q;

int main(){
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int fs[26], ft[26];
        memset(fs,0,sizeof(fs));
        memset(ft,0,sizeof(ft));
        for(int i=0;i<n;i++){
            fs[s[i]-'a']++;
            ft[t[i]-'a']++;
        }
        bool work = true;
        for(int i=0;i<26;i++){
            if(fs[i]!=ft[i]){
                work = false;
            }
        }
        
        if(!work){
            cout << "NO" << endl;
            continue;
        }
        bool finish = false;
        for(int i=0;i<26;i++){
            if(fs[i]>=2){
                finish = true;
                break;
            }
        }
        if(finish){
            cout << "YES" << endl;
            continue;
        }
        int numMoves = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(t[j]==s[i]){
                    numMoves+=(j-i);
                    t = t.substr(0,j)+t.substr(j+1,n-i);
                    s = s.substr(1,n-i);
                    i =0; j =0;
                    n--;
                    break;
                }
            }
        }
        if(numMoves%2==0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}