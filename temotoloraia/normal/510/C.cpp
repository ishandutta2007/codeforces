#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
bool g[26][26];
int gg[26];
bool fix[26];
int main() {
    int n;
    string s,ss;
    cin>>n>>s;
    n--;
    while (n--){
        cin>>ss;
        int x=100,y=100;
        for (int i=0;i<s.size() && i<ss.size();i++){
            if (s[i]!=ss[i]){
                x=s[i]-'a';
                y=ss[i]-'a';
                break;
            }
        }
        if (x==100 && s.size()<ss.size()){s=ss;continue;}
        s=ss;
        if (x==100){
            cout<<"Impossible";
            return 0;
        }
        if (g[x][y]==0)
            gg[y]++;
        g[x][y]=1;
    }
    string ans="";
    while (1){
        int I=-1;
        for (int i=0;i<26;i++)
            if (gg[i]==0 && fix[i]==0)
                I=i;
        if (I==-1){
            cout<<"Impossible";
            return 0;
        }
        ans+=(I+'a');
        fix[I]=1;
        for (int i=0;i<26;i++)
            gg[i]-=g[I][i];
        if (ans.size()==26){
            cout<<ans;
            return 0;
        }
    }
    return 0;
}