#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int cnt[26];

bool find(int l, string s, int k){
    int pos = (l+k-1) % 26;
    int t = 25-pos;
    //cout<<pos<<" "<<t<<endl;
    //cout<<s[pos]<<endl;
    //cout<<s[t]<<" "<<s[t-1]<<endl;
    //cout<<s[t]-'A'<<" "<<s[t-1]-'A'<<endl;
    return (cnt[s[t]-'A']==2) || ((t-1)!=12 && (t-1)!=-1 && cnt[s[t-1]-'A']==2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    char a;
    int i=0,k;
    for(char c:s) {
        if(!cnt[c-'A']++) t.push_back(c);
        else a=c,k=i;
        i++;
    }
    if(s[k-1]==a) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int l=0;
    while(!find(l,t,k)) l++,rotate(t.begin(),t.end()-1,t.end());
    reverse(t.begin()+13,t.end());
    cout<<t.substr(0,13)<<endl<<t.substr(13)<<endl;
    return 0;
}