#include <bits/stdc++.h>
using namespace std;

string used[] = {
"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P",
"S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN",
"GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH",
"PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND",
"PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE",
"OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH",
"PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG",
"BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};
string s;
int dp[10005];

int main() {
  cin >> s;
  int n = s.size();
  s = ' ' + s;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 117; j++) {
      if (i >= used[j].size() && s.substr(i - used[j].size() + 1, used[j].size()) == used[j]) {
        dp[i] |= dp[i - used[j].size()];
      }
    }
  }  
  if (dp[n]) cout << "YES"; else cout << "NO";
}