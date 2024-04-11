#include<stdio.h>
#include<vector>

using namespace std;
  vector<char>num;

int pow2(int p){
  if(p==0){return 1;}
  if(p%2==0){int m=pow2(p/2);return m*m;}
  else{
    return pow2(p-1)*2;
  }
}

bool eq(vector<char>a,vector<char>b){
  for (size_t i=0;i<a.size();i++){if(a[i]!=b[i]){return false;}}
  return true;
}

int cpos=0;
int l;
int npos=-1;
vector<char>cn;

void find(int pos){
  if(pos==l){cpos++;if(eq(cn,num)){npos=cpos;}return;}
  find(pos+1);
  cn[pos]=11-cn[pos];
  find(pos+1);
  cn[pos]=11-cn[pos];
}

int main(){
  int n;
  scanf("%d",&n);
  vector<char>raw;
  while(n>0){raw.push_back(n%10);n/=10;}
  num.resize(raw.size());l=num.size();
  for (int i=0;i<l;i++){
    num[i]=raw[l-i-1];
  }
  int pos=-1;
  for (int i=l;i>0;i--){pos+=pow2(i-1);}
  cn.resize(l);cn.assign(l,4);
  find(0);
  pos+=npos;
  printf("%d",pos);

}