#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

int l, f;
string s;

int main(){
    cin >> s; l = s.size();
    for(char c : s) if(c=='1') f++;
    if(f<2) l--;
    printf("%d\n",(l+1)/2);
    return 0;
}