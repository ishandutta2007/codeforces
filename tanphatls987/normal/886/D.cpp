#include <bits/stdc++.h>

using namespace std;

const int N=1e5+20;
const int MOD=1e9+7;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int alp=26;

int v[alp][alp],h[alp];

int main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof(h));
    while (n--){
        string s;
        cin>>s;
        for(int i=0;i<s.length()-1;i++) v[s[i]-'a'][s[i+1]-'a']=1;
        for(auto ch:s) h[ch-'a']=0;
    }
    string ans;
    for(int st=0;st<alp;st++) if (h[st]!=-1){
        int n1=0;
        for(int i=0;i<alp;i++) n1+=v[i][st];
        if (n1) continue;
        int cur=st;
        while (1){
            h[cur]=1;
            ans.push_back(cur+'a');
            int deg=count(v[cur],v[cur]+alp,1);
            if (deg>1){
                cout<<"NO";
                return 0;
            }
            if (!deg) break;
            int ncur=0;
            while (!v[cur][ncur]) ncur++;
            if (h[ncur]){
                cout<<"NO";
                return 0;
            }
            cur=ncur;
        }
    }
    if (count(h,h+alp,0)){
        cout<<"NO";
        return 0;
    }
    cout<<ans;
}