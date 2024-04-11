#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 vector<int>a(n);
 for(int &i:a)
  cin>>i;
 multiset<int>b;
 for(int i=0,j;i<n;++i)
  cin>>j,b.insert(j);
 for(int i=0;i<n;++i){
  auto it=b.lower_bound(n-a[i]);
  if(it==b.end())
   it=b.begin();
  cout<<(a[i]+*it)%n<<" ";
  b.erase(it);
 }
}