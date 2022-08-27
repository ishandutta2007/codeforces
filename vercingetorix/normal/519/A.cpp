#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans=0;
    int n;
    char c;
    int p1=0;
    int p2=0;
    vi v(256, 0);
    v['p'] =1; v['P'] =1;
    v['N'] =3; v['n'] =3;
    v['B'] =3; v['b'] =3;
    v['R'] =5; v['r'] =5;
    v['Q'] =9; v['q'] =9;
    for(int i=0; i<64; i++) {
        cin>>c;
        if(c>='a' && c<='z') p1+=v[c];
        else p2+=v[c];
    }
    if(p2>p1) cout<<"White";
    else if (p1>p2) cout<<"Black";
    else cout<< "Draw";

}