#include <bits/stdc++.h>
using namespace std;

#define ab(a) max(a,-(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> sizeaxl(3,0),sizeaxs(3,0),sizeam(3,0),sizebxl(3,0),sizebxs(3,0),sizebm(3,0);
  string s;
  for(int i=0;i<n;i++){
    cin >> s;
    if(s=="XXXL"){
      sizeaxl[0]++;
    }else if(s=="XXL"){
      sizeaxl[1]++;
    }else if(s=="XL"){
      sizeaxl[2]++;
    }else if(s=="L"){
      sizeam[0]++;
    }else if(s=="M"){
      sizeam[1]++;
    }else if(s=="S"){
      sizeam[2]++;
    }
  }
  for(int i=0;i<n;i++){
    cin >> s;
    if(s=="XXXL"){
      sizebxl[0]++;
    }else if(s=="XXL"){
      sizebxl[1]++;
    }else if(s=="XL"){
      sizebxl[2]++;
    }else if(s=="L"){
      sizebm[0]++;
    }else if(s=="M"){
      sizebm[1]++;
    }else if(s=="S"){
      sizebm[2]++;
    }
  }
  int count=0;
  for(int i=0;i<3;i++){
    if(sizeam[i]-sizebm[i]>0){
      count+=sizeam[i]-sizebm[i];
    }
  }
  cout << ab(sizeaxl[0]-sizebxl[0])+ab(sizeaxl[1]-sizebxl[1])+ab(sizeaxl[2]-sizebxl[2])+count << endl;
  return 0;
}