#include <bits/stdc++.h>
using namespace std;

long long a[30], b[30], n, i, j, len, f, c, l1, l2, nou;
string s, t[100005];

long long solve(long long st){
    memset(a, 0, sizeof(a)); nou=0;
    memset(b,0,sizeof(b));
    string s = t[st];
    for(i=0;i<s.size();i++){
        if(!i||s[i]!=s[i-1]){
            if(i) a[s[i-1]-'a']=max(a[s[i-1]-'a'],c);
            c = 1;
        }
        else c++;
    }
    a[s.back()-'a'] = max(a[s.back()-'a'], c);
    for(i=st+1;i<=n;i++){
        s = t[i]; f = 1; c = 0;
        memset(b, 0, sizeof(b));
        for(j=1;j<s.size();j++){
            if(s[j]!=s[j-1]) f = 0;
        }
        if(f) b[s[0]-'a']=max(b[s[0]-'a'],(a[s[0]-'a']+1)*s.size()+a[s[0]-'a']);
        for(j=0;j<s.size();j++){
            if(!j||s[j]!=s[j-1]){
                if(j) b[s[j-1]-'a']=max(b[s[j-1]-'a'],c);
                c = 1;
            }
            else c ++;
        }
        if(a[s.back()-'a']) b[s.back()-'a']=max(b[s.back()-'a'],c+1);
        else b[s.back()-'a']=max(b[s.back()-'a'],c);
        if(!f){
            l1 = l2 = 0;
            for(j=1;j<s.size();j++){
                l1 ++;
                if(s[j]!=s[j-1]) break;
            }
            for(j=s.size()-2;j>=0;j--){
                l2 ++;
                if(s[j]!=s[j+1]) break;
            }
            if(s[0]==s.back())b[s[0]-'a']=max(b[s[0]-'a'],1+l1+l2);
            else{
                if(a[s[0]-'a']) b[s[0]-'a']=max(b[s[0]-'a'], l1+1);
                if(a[s.back()-'a']) b[s.back()-'a']=max(b[s.back()-'a'],l2+1);
            }
        }
        for(j=0;j<26;j++) if(a[j]) b[j]=max(b[j],1LL);
        for(j=0;j<26;j++) b[j]=min(b[j],1000000000LL);
        swap(a, b);
    }
    long long ans = 0;
    for(i=0;i<26;i++) ans = max(ans, a[i]);
    return ans;
}
int main(){
    cin >> n;
    for(i=1;i<=n;i++) cin >> t[i];
    printf("%lld\n",solve(1));
    return 0;
}