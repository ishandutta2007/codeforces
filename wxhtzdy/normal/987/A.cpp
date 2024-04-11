#include <bits/stdc++.h>
using namespace std;
pair<string,string> v[6]={{"purple","Power"},{"green","Time"},{"blue","Space"},{"orange","Soul"},{"red","Reality"},{"yellow","Mind"}};
int main(){
  int n;
  cin>>n;
  map<string,int> cnt;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    cnt[s]++;
  }
  cout<<6-n<<endl;
  for(auto c:v){
    if(cnt[c.first]==0)cout<<c.second<<endl;
  }
}