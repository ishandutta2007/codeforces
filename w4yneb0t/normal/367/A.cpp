#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
string s;
in ct[100009][3];
in m,l,r;
int main(){
  cin>>s;
  cin>>m;
  in n=s.length();
  for(in i=0;i<3;i++)
    ct[0][i]=0;
  for(in i=0;i<n;i++){
    in cr=s[i]-'x';
    for(in j=0;j<3;j++){
      ct[i+1][j]=ct[i][j];
    }
    ct[i+1][cr]++;
  }
  in nb[3];
  for(in z=0;z<m;z++){
    cin>>l>>r;
    for(in j=0;j<3;j++)
      nb[j]=ct[r][j]-ct[l-1][j];
    sort(nb,nb+3);
    if(r-l<=1 || nb[2]-nb[0]<=1)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}