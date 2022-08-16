#include <bits/stdc++.h>

#define FOR(i,n) for(int i =0;i<n;i++)
#define ll long long int
#define vi vector<int>

using namespace std;

bool isPos(int n,int k,int odp){
  if(k<odp)return false;
  if(n/k %2 ==0)return odp == 0;
  else return (k-odp)%2 == 0;
}
stack<char> odd;
void printPalin(int* as,int* al,int* dg,int ln){
  string f="",b="";
  int num = ln/2;
  int ptr1=0,ptr2=0,ptr3 =0;
  if(ln %2 ==0){
    FOR(i,num){
      while(ptr1 <26 && (as[ptr1]==0 || as[ptr1]%2==1))ptr1++;
      if(ptr1 >= 26){
        while(ptr2 <26 && (al[ptr2]==0 || al[ptr2]%2==1))ptr2++;
        if(ptr2 == 26){
          while(ptr3 <10 && (dg[ptr3]==0 || dg[ptr3]%2==1))ptr3++;
          f+=(char)(ptr3+'0');
          b=(char)(ptr3+'0') + b;
          dg[ptr3]-=2;
        }else{
          f+=(char)(ptr2+'A');
          b=(char)(ptr2+'A') + b;
          al[ptr2]-=2;
        }
      }else{
        f+=(char)(ptr1+'a');
        b=(char)(ptr1+'a') + b;
        as[ptr1]-=2;
      }
    }
    cout<<f<<b<<" ";
  }else{
    FOR(i,num){
      while(ptr1 <26 && (as[ptr1]==0 || as[ptr1]%2==1))ptr1++;
      if(ptr1 >= 26){
        while(ptr2 <26 && (al[ptr2]==0 || al[ptr2]%2==1))ptr2++;
        if(ptr2 == 26){
          while(ptr3 <10 && (dg[ptr3]==0 || dg[ptr3]%2==1))ptr3++;
          f+=(char)(ptr3+'0');
          b=(char)(ptr3+'0') + b;
          dg[ptr3]-=2;
        }else{
          f+=(char)(ptr2+'A');
          b=(char)(ptr2+'A') + b;
          al[ptr2]-=2;
        }
      }else{
        f+=(char)(ptr1+'a');
        b=(char)(ptr1+'a') + b;
        as[ptr1]-=2;
      }
    }
    if(odd.size()==0){
      bool ok=false;
      FOR(i,26){
        if(ok)break;
        if(as[i]!=0){
          as[i]-=2;
          odd.push(i+'a');
          odd.push(i+'a');
          ok=true;
        }
      }
      FOR(i,26){
        if(ok)break;
        if(al[i]!=0){
          al[i]-=2;
          odd.push(i+'A');
          odd.push(i+'A');
          ok=true;
        }
      }
      FOR(i,10){
        if(ok)break;
        if(dg[i]!=0){
          dg[i]-=2;
          odd.push(i+'0');
          odd.push(i+'0');
          ok=true;
        }
      }
    }
    cout<<f<<odd.top()<<b<<" ";
    odd.pop();

  }
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int as[26];
  int al[26];
  int dg[10];
  FOR(i,26)as[i]=0,al[i]=0,dg[i]=0;
  FOR(i,n){
    if(s[i]>='a')as[s[i]-'a']++;
    else if(s[i]>='A')al[s[i]-'A']++;
    else dg[s[i]-'0']++;
  }
  int odp = 0;
  FOR(i,26){odp+=as[i]%2 + al[i]%2;
    if(as[i]%2==1)odd.push(i+'a'),as[i]-=1;;
    if(al[i]%2==1)odd.push(i+'A'),al[i]-=1;

  }
  FOR(i,10){
    odp+=dg[i]%2;
    if(dg[i]%2==1)odd.push(i+'0'),dg[i]--;;
  }


  for(int i=1;i<=n;i++){
    if(n%i==0){
      if(isPos(n,i,odp)){
        cout<<i<<endl;
        FOR(j,i){
            printPalin(as,al,dg,n/i);
        }
        cout<<endl;
        return 0;
      }
    }
  }

  return 0;
}