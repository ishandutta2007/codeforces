#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> d[26];
    for (int i=0;i<n;i++){
        int spot= s[i]-'a';
        d[spot].push_back(i);
    }
    
    int res=0;
    
    for (auto i: d){
        int maxok=0;
        for (int k=0;k<n;k++)
        {
            int cnt[26]={0};
            for (auto j:i){
                cnt[(int)(s[(j+k)%n]-'a')]++;
            }
            int pmo=0;
            for (auto j:cnt){ if (j==1) pmo++;}
            maxok=max(maxok,pmo);
            if (maxok==i.size()) {break;}
        }
        res+=maxok;
    }
    printf("%.8f",res/float(n));
}