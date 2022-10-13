#include <bits/stdc++.h>

using namespace std;
#define ll long long
int f[10];
int dig[10];
string s;
int find(int i,int j){
    int num = i;
    int ret =0;
    for(int x=0;x<s.length();x++){
       
        if(s[x]-'0'==num){
            ret++;
            if(num==i) num=j;
            else num=i;
        }
    }

    return ret;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        for(int i=0;i<10;i++) f[i]= 0;
        
        for(int i=0;i<s.length();i++){
            f[s[i]-'0']++;
        }
        int maxFreq =0;
        for(int i=0;i<10;i++){
            maxFreq = max(maxFreq,f[i]);
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(j==i) continue;
                int x = find(i,j);
                if(x%2) x--;
                maxFreq = max(maxFreq,x);
            }
        }
        cout << s.length()-maxFreq << endl;
    }
}