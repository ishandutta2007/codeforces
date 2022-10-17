#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,b) FOR(i,0,b)
#define X first 
#define Y second
#define PB push_back
#define ALLOF(a) (a).begin(),(a).end()
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

void sort(string& s,int t){
    if(t==s.size())return;
    string so=s;
    REP(k,s.size()/t){
        string s1,s2;
        s1=s.substr(k*t,t);
        s2=s.substr(k*t+t,t);
        if(s1>s2)swap(s1,s2);
        // cout<<"# "<<s1<<" "<<s2<<endl;
        REP(i,t){
            so[k*t+i]=s1[i];
        }
        REP(i,t){
            so[k*t+t+i]=s2[i];
        }
        // cout<<"# "<<so<<endl;
        k++;
    }
    swap(s,so);
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int k=1;
    while(s1.size() % k == 0)k<<=1;
    k>>=1;
    int t=s1.size()/k;
    for(int i=t;i<=s1.size();i<<=1){
        sort(s1,i);
        sort(s2,i);
        // cout<<":"<<i<<" "<<s1<<" "<<s2<<endl;
    }
    if(s1==s2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}