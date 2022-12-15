#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

int i, a, b;
string s;

int main(){
    cin >> s;
    for(i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            a++;
            if(a>b) s[i]='0', b++;
        }
        else b++;
    }
    cout << s.c_str() << endl;
    return 0;
}