#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>

using namespace std;

int yy,mm,dd,by,bm,bd;
int mday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool valid(int y, int m, int d){
  if(m > 12 || m== 0) return false;
  if(d > 31 || d == 0) return false;
  if(y == 0) return false;
  if(d <= mday[m]) return true;
  if(y % 4 == 0 && m == 2 && d == 29) return true;
  return false;
}

bool solve(int y, int m, int d){
  if(!valid(y,m,d)) return false;
  if(m < mm || (m == mm && d <= dd)){
    return yy >= y + 18;
  }else {
    return yy > y + 18;
  }
}


bool solve(){
  return solve(by, bm, bd) || solve(by, bd, bm) || solve(bm, by, bd) 
    || solve(bm, bd, by) || solve(bd, by, bm) || solve(bd, bm, by);
}

int main(){
  string a, b;
  cin >> a >> b;
  dd = (a[0] - '0') * 10 + a[1] - '0';
  mm = (a[3] - '0') * 10 + a[4] - '0';
  yy = (a[6] - '0') * 10 + a[7] - '0';
  bd = (b[0] - '0') * 10 + b[1] - '0';
  bm = (b[3] - '0') * 10 + b[4] - '0';
  by = (b[6] - '0') * 10 + b[7] - '0';
  if(solve()){
    cout<< "YES";
  }else {
    cout << "NO";
  }
  return 0;
}