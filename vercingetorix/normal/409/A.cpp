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

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
std::string s1,s2;
cin>>s1;
cin>>s2;
int m1=0,m2=0;
for(int i=0; i<s1.length(); i+=2){
    char c1=s1[i];
    char c2=s2[i];
    if(c1==c2) continue;
    if((c1=='[')&&(c2=='8')) m2++;
    else if((c1=='8')&&(c2=='(')) m2++;
    else if((c1=='(')&&(c2=='[')) m2++;
    else m1++;
}
if(m1>m2) cout<<"TEAM 1 WINS";
if(m1<m2) cout<<"TEAM 2 WINS";
if(m1==m2) cout<<"TIE";

  return 0;
}