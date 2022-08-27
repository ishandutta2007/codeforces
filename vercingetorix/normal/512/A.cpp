#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
bool so[30][30];
int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int n,d,x,y;
int ans = 0;
cin>>n;
vector<string> names(n);
for(int i=0;i<30;i++) for(int j=0;j<30;j++) so[i][j]=false;
for(int i=0; i<n; i++) cin>>names[i];
vb razr(n-1, false);
for(int symb=0; symb<100; symb++) {
    for(int i=0; i<n-1; i++) {
        if(razr[i]) continue;
        if (names[i+1].length()<symb+1) {
            cout<<"Impossible";
            return 0;
        }
        if (names[i+1].length()<symb+1) {
            razr[i]=true;
            continue;
        }
        if(names[i][symb]!=names[i+1][symb]){
            razr[i]=true;
            so[names[i][symb]-'a'][names[i+1][symb]-'a'] = true;
        }
    }
}

vi dob(30, 0);
vb  used(26, false);
for(int i=0;i<30;i++) for(int j=0;j<30;j++) if(so[i][j]) dob[j]++;
string sans;
for(int i=0; i<26; i++){
    bool f=false;
    for(int j=0; j<26; j++) {
        if((dob[j]==0)&&(!used[j])) {
            sans.pb('a'+j);
            f=true;
            used[j]=true;
            for(int k=0; k<26; k++) if(so[j][k]) dob[k]--;
            break;
        }
    }
    if(!f) {
        cout<<"Impossible";
        return 0;
    }
}
cout<<sans;
 return 0;
}