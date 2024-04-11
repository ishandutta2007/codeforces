#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  int zero=-1;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==0) zero=i;
  }
  int pre;
  int ze=0;
  for(int i=0;i<n;i++){
    if(a[i]==0){
      if(ze==0){
        if(i==0) pre=-1;
        else pre=a[i-1];
      }
      ze++;
    }else{
      if(ze>0){
        for(int j=1;j<=ze;j++){
          a[i-j]=max(pre,a[i]);
        }
        ze=0;
      }
    }
  }
  if(ze>0){
    if(pre==-1){
      cout << "YES" << endl;
      for(int i=0;i<n-1;i++) printf("%d ",q);
      cout << q << endl;
      return 0;
    }
    for(int j=1;j<=ze;j++){
      a[n-j]=pre;
    }
  }
  vector<int> r(q+1,-1);
  for(int i=0;i<n;i++){
    r[a[i]]=i;
  }
  if(r[q]==-1&&zero==-1){
    cout << "NO" << endl;
    return 0;
  }
  stack<int> st;
  st.push(-1);
  for(int i=0;i<n;i++){
    if(a[i]>st.top()){
      st.push(a[i]);
    }else if(a[i]<st.top()){
      while(st.top()>a[i]){
        if(r[st.top()]>i){
          cout << "NO" << endl;
          return 0;
        }
        st.pop();
      }
    }
  }
  cout << "YES" << endl;
  if(r[q]==-1) a[zero]=q;
  for(int i=0;i<n-1;i++) printf("%d ",a[i]);
  cout << a[n-1] << endl;
  return 0;
}