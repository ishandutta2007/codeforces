#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  char w[60];
  int sw;
  cin>>w;
  cin>>sw;
  for(int i=0;w[i]!='\0';i++){
    if((int)w[i]<=96)
      w[i]+=32;
    if((int)w[i]<sw+97)
      w[i]-=32;
    cout<<w[i];
  }
  cout<<endl;
  return 0;
}