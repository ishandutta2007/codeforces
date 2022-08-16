#include<bits/stdc++.h>
using namespace std;

string s,t;
int n;

bool same(int s1,int s2, int t1,int t2){
  int cur = s1-1;
  int cur2 = t1-1;
  while(cur < s2){
    if(s[cur] != t[cur2]) return false;
    cur ++; cur2++;
  }
  return true;
}

bool equi(int s1,int s2,int t1,int t2,int l){
  if(same(s1,s2,t1,t2)) return 1;
  if(l%2) return 0;
  int mid1 = (s1+s2)/2;
  int mid2 = (t1+t2)/2;
  return ((equi(s1,mid1,t1,mid2,l/2))and(equi(mid1+1,s2,mid2+1,t2,l/2))) or ((equi(s1,mid1,mid2+1,t2,l/2))and(equi(mid1+1,s2,t1,mid2,l/2)));
}

int main(){
  cin >> s >> t;
  n = s.length();
  if(equi(1,n,1,n,n)) cout << "YES\n";
  else cout << "NO\n";
}

/*s = input()
t = input()
n = len(s)

def equi(s1,s2,t1,t2,l):
  if s[s1-1:s2] == t[t1-1:t2]: return 1  
  elif l%2 == 0:
    mid1 = (s1+s2)//2
    mid2 = (t1+t2)//2
    return ((equi(s1,mid1,t1,mid2,l//2))and(equi(mid1+1,s2,mid2+1,t2,l//2))) or ((equi(s1,mid1,mid2+1,t2,l//2))and(equi(mid1+1,s2,t1,mid2,l//2)))
  return 0  
if equi(1,n,1,n,n):
  print("YES")
else:
  print("NO")*/