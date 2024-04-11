#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        string s;cin>>s;
        int n=(int)s.size();
        set<char> c;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i>0&&s[i]==s[i-1])cnt++;
            else{
                if(cnt%2==1)c.insert(s[i-1]);
                cnt=1;
            }
        }
        if(cnt%2==1)c.insert(s[n-1]);
        for(char p:c)printf("%c",p);
        printf("\n");
    }
    return 0;
}