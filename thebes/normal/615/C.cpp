#include <bits/stdc++.h>
using namespace std;

const int MN = 2102;
int t[MN*MN][26], p, nxt, i, j;
pair<int,int> id[2*MN*MN];
vector<pair<int,int>> ans;
string a, b;

int main(){
    cin >> a >> b;
    for(i=0;i<a.size();i++){
        p = 0;
        for(j=i;j<a.size();j++){
            if(!t[p][a[j]-'a'])
                t[p][a[j]-'a'] = ++nxt;
            p = t[p][a[j]-'a'];
            id[p] = {i+1, j+1};
        }
    }
    for(i=a.size()-1;i>=0;i--){
        p = 0;
        for(j=i;j>=0;j--){
            if(!t[p][a[j]-'a'])
                t[p][a[j]-'a'] = ++nxt;
            p = t[p][a[j]-'a'];
            id[p] = {i+1,j+1};
        }
    }
    for(i=0;i<b.size();i=j){
        p = 0;
        for(j=i;j<b.size();j++){
            if(!t[p][b[j]-'a']) break;
            p = t[p][b[j]-'a'];
        }
        if(i==j){
            printf("-1\n");
            return 0;
        }
        ans.push_back(id[p]);
    }
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d %d\n",v.first,v.second);
    return 0;
}