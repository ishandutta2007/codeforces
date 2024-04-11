#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)

const string r="qwertyuiopasdfghjkl;zxcvbnm,./";
char t;
string s;
int main()
{
    cin>>t>>s;
    FOR(i,1,s.length()){
            FOR(k,0,r.length()-1) if (s[i-1]==r[k]){
                if (t=='L') cout<<r[k+1];else cout<<r[k-1];
            }
    }
}