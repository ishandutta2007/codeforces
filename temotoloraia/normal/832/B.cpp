#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
string s,ss;
int a[30];
int I,n,T;
bool ok;
int main() {
    cin>>s;
    for (int i=0;i<s.size();i++)
        a[s[i]-'a']=1;
    cin>>s>>T;
    n=s.size();
    I=n;
    for (int i=0;i<n;i++)
        if (s[i]=='*')
            I=i;
    while (T--){
        cin>>ss;
        if (ss.size()<n-1 || (I==n && ss.size()!=n)){
            printf("NO\n");
            continue;
        }
        ok=0;
        for (int i=0;i<I && i<ss.size();i++){
            if (s[i]!='?' && s[i]!=ss[i])
                ok=1;
            if (s[i]=='?' && a[ss[i]-'a']==0)
                ok=1;
        }
        for (int i=n-1;i>I;i--)
            if (0<=ss.size()-1-(n-1-i) && ss.size()-1-(n-1-i)<ss.size()){
            if (s[i]!='?' && s[i]!=ss[ss.size()-1-(n-1-i)])
                ok=1;
            if (s[i]=='?' && a[ss[ss.size()-1-(n-1-i)]-'a']==0)
                ok=1;
        }
        if (I!=n){
        if (I-n>-1)while (1)cout<<1;
        for (int i=I;i<=I+(int)ss.size()-n/* && i<ss.size()*/;i++)
            if (a[ss[i]-'a'])
                ok=1;
        }
        if (ok){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}