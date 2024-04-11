#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int n,k;
bool ret;
int wild;
bool works(int x){
    int num = 0;
    int tot = 0;
    bool found = false;
    for(int i=x;i<n;i+=k){
        if(s[i]!='?') {
            found = true;
            num+=(s[i]-'0');
            ++tot;
        }
    }
    if(num>0 && num<tot) return false;
    if(num==0 && !found) return true;
    for(int i=x;i<n;i+=k){
        if(s[i]=='?'){
            if(num==0) s[i]='0';
            else s[i]='1';
        }
    }
    return true;
   
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        ret = true;
        wild = 0;
        for(int i=0;i<k;i++) ret=  ret&&works(i);
        int cnt = 0;
        int currWild = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='?') ++currWild;
            else{
                if(s[i]=='1') ++cnt;
                else --cnt;
            }
        }
        ret = ret&&((cnt%2+2)%2==(currWild%2+2)%2)&&(cnt-currWild <=0 && cnt+currWild>=0);
        for(int i=k;i<n;i++){
            if(s[i]=='?') ++currWild;
            else{
                if(s[i]=='1') ++cnt;
                else --cnt;
            }
            if(s[i-k]=='?') --currWild;
            else{
                if(s[i-k]=='1') --cnt;
                else ++cnt;
            }
            ret = ret&&((cnt%2+2)%2==(currWild%2+2)%2)&&(cnt-currWild <=0 && cnt+currWild>=0);
        
        }
        if(ret) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}