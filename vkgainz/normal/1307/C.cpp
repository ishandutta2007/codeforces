#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll calc(int a,int b){
    ll res = 0;
    if(a==b){
        for(int i=0;i<s.length();i++){
            if(s[i]-'a'==a) res++;
        }
        if(res>2) res = res*(res-1)/2;
    }
    else{
        int x =0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]-'a'==b) x++;
            if(s[i]-'a'==a) res+=x;
        }
    }
    return res;
}
int main(){
    cin >> s;
    ll ret =0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(calc(i,j)>ret)
                ret = calc(i,j);
    cout << ret << endl;

}