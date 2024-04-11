#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

int n, t, i, p, l, c, e;
string s;

int main(){
    cin >> n >> t >> s;
    for(i=0;i<s.size();i++) if(s[i]=='.') break;
    p = i; e = s.size();
    for(i=p+1;i<s.size();i++){
        if(s[i]>='5'){
            while(t--){
                if(s[i]<'5') break;
                if(i-1==p){
                    c = 1;
                    for(i=p-1;i>=0;i--){
                        s[i]+=c; c=0;
                        if(s[i]>'9'){
                            s[i]='0';
                            c = 1;
                        }
                    }
                    if(c) s.insert(s.begin(),'1'), e = p+1;
                    else e = p;
                }
                else{
                    s[i-1]++;
                    i--; e = i+1;
                }
            }
            break;
        }
    }
    for(i=0;i<e;i++) printf("%c",s[i]);
    printf("\n");
    return 0;
}