#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s;
int n;
int k;
bool works(string a,string b){
    bool foundLess = false;
    bool foundMore = false;
    for(int i=0;i<n;i++){
        if(a[i]-'0' > b[i]-'0'){
            return true;
        }
        else if(a[i]-'0' <b[i]-'0'){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> n >> k;
    cin >> s;
    string temp = "";
    for(int i=0;i<k;i++){
        temp+=s[i];
    }
    for(int i=k;i<n;i++){
        temp+=temp[i-k];
    }
    cout << n << endl;
    if(works(temp,s)){
        cout << temp << endl;
    }
    else{
        int left = k;
        for(int i=k-1;i>=0;i--){
            if(s[i]!='9'){
                left = i;
                break;
            }
        }
        temp = "";
        for(int i=0;i<k;i++){
            if(i<left){
                temp+=s[i];
            }
            else if(i==left){
                temp+=(s[i]+1);
            }
            else{
                temp+=('0');
            }
        }
        for(int i=k;i<n;i++){
            temp+=temp[i-k];
        }
        cout << temp << endl;
    }
    
}