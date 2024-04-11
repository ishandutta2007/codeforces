#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main(){
  //int t;scanf("%i",&t);
  int t;cin>>t;
  vector<pii> all;
  while(t--){
    int n;cin>>n;//scanf("%i",&n);
    auto Ask=[&](int x,int y){
      if(x==y)return '=';
      //printf("? %i %i\n",x+1,y+1);
      cout<<"? "<<x+1<<" "<<y+1<<endl;
      //fflush(stdout);
      char c;cin>>c;//scanf("%c",&c);
      return c;
    };
    vector<int> x,y;
    for(int i=0;i<n;i+=2){
      if(i==n-1){
        x.push_back(i);
        y.push_back(i);
        continue;
      }
      auto c=Ask(i,i+1);
      if(c=='<')x.push_back(i),y.push_back(i+1);
      else y.push_back(i),x.push_back(i+1);
    }
    //assert(!x.empty());
    //assert(!y.empty());
    int mn=x[0];
    for(int i:x){
      auto c=Ask(mn,i);
      if(c=='>')mn=i;
    }
    int mx=y[0];
    for(int i:y){
      auto c=Ask(mx,i);
      if(c=='<')mx=i;
    }
    cout<<"! "<<mn+1<<" "<<mx+1<<endl;
    //printf("! %i %i\n",mn+1,mx+1);
    //fflush(stdout);
  }
  return 0;
}