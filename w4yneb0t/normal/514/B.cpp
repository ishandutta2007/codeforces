#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int ggt(int a, int b){
if(b==0)return a;
return ggt(b,a%b);
}
pair<int,int> nrm(int a, int b){
return make_pair(a/ggt(a,b),b/ggt(a,b));
}
set<pair<int,int> > s;
int main(){
int n;
cin>>n;
int x0,y0;
cin>>x0>>y0;
int x,y;
for(int i=0;i<n;i++){
cin>>x>>y;
x-=x0;
y-=y0;
s.insert(nrm(x,y));
}
cout<<s.size()<<endl;
return 0;
}