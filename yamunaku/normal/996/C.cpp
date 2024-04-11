#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> space(2*n),park(2*n),vspace(2*n),vpark(2*n);
  for(int j=0;j<n;j++){
    cin >> park[j];
    vpark[j]=park[j];
  }
  for(int j=0;j<n;j++){
    cin >> space[j];
    vspace[j]=space[j];
  }
  for(int j=0;j<n;j++){
    cin >> space[2*n-j-1];
    vspace[2*n-j-1]=space[2*n-j-1];
  }
  for(int j=0;j<n;j++){
    cin >> park[2*n-j-1];
    vpark[2*n-j-1]=park[2*n-j-1];
  }
  // for(int i=0;i<2*n;i++){
  //   cout << space[i] << " ";
  // }
  // cout << endl;
  bool flag=false;
  int zero;
  for(int j=0;j<2*n;j++){
    if(space[j]==0||space[j]==park[j]){
      flag=true;
      zero=j;
    }
  }
  if(!flag){
    cout << -1 << endl;
    return 0;
  }
  int count=0;
  int C=0;
  while(1){
    // for(int i=0;i<2*n;i++){
    //   cout << space[i] << " ";
    // }
    //   cout << endl;
    //   cout << count << endl;
    for(int j=0;j<2*n;j++){
      if(space[j]&&space[j]==park[j]){
        C++;
        count++;
        space[j]=0;
      }
    }
    if(count==k) break;
    for(int i=0;i<2*n-1;i++){
      if(space[(zero+i+1)%(2*n)]){
        C++;
        space[(zero+i)%(2*n)]=space[(zero+i+1)%(2*n)];
        space[(zero+i+1)%(2*n)]=0;
      }
    }
    zero=(zero+2*n-1)%(2*n);
  }
  cout << C << endl;
  count=0;
  for(int j=0;j<2*n;j++){
    if(vspace[j]==0||vspace[j]==vpark[j]){
      zero=j;
    }
  }
  while(1){
    for(int j=0;j<2*n;j++){
      if(vspace[j]&&vspace[j]==vpark[j]){
        printf("%d %d %d\n",vspace[j],(j<n?1:4),(j<n?j+1:2*n-j));
        count++;
        vspace[j]=0;
      }
    }
    if(count==k) return 0;
    for(int i=0;i<2*n-1;i++){
      if(vspace[(zero+i+1)%(2*n)]){
        printf("%d %d %d\n",vspace[(zero+i+1)%(2*n)],((zero+i)%(2*n)<n?2:3),((zero+i)%(2*n)<n?(zero+i)%(2*n)+1:2*n-(zero+i)%(2*n)));
        vspace[(zero+i)%(2*n)]=vspace[(zero+i+1)%(2*n)];
        vspace[(zero+i+1)%(2*n)]=0;

          // for(int i=0;i<2*n;i++){
          //   cout << vspace[i] << " ";
          // }
          //   cout << endl;
          //   cout << count << endl;
      }
    }
    zero=(zero+2*n-1)%(2*n);
  }
  return 0;
}