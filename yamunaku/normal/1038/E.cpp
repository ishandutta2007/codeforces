#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<vector<LL>> e(6,vector<LL>(n));
  vector<vector<int>> mp={
    {-1,0,1,2},
    {0,-1,3,4},
    {1,3,-1,5},
    {2,4,5,-1},
  };
  vector<int> count(6,0);
  vector<LL> jiko(4,0);
  int c1,c2,V;
  for(int i=0;i<n;i++){
    cin >> c1 >> V >> c2;
    c1--;
    c2--;
    if(c1==c2){
      jiko[c1]+=V;
    }else{
      e[mp[c1][c2]][count[mp[c1][c2]]]=V;
      count[mp[c1][c2]]++;
    }
  }
  for(int i=0;i<6;i++) sort(e[i].begin(),e[i].end(),greater<LL>());
  for(int i=0;i<6;i++){
    for(int j=1;j<count[i];j++){
      e[i][j]+=e[i][j-1];
    }
  }
  vector<int> v(4,0);
  int ki;
  LL ans=0,tmp;
  for(int i0=0;i0<=count[0];i0++){
    for(int i1=0;i1<=count[1];i1++){
      for(int i2=0;i2<=count[2];i2++){
        for(int i3=0;i3<=count[3];i3++){
          for(int i4=0;i4<=count[4];i4++){
            for(int i5=0;i5<=count[5];i5++){
              for(int i=0;i<4;i++) v[i]=0;
              v[0]=i0+i1+i2;
              v[1]=i0+i3+i4;
              v[2]=i1+i3+i5;
              v[3]=i2+i4+i5;
              ki=v[0]%2+v[1]%2+v[2]%2+v[3]%2;
              if(ki==0||ki==2){
                if(v[0]+v[1]>0&&v[2]+v[3]>0&&i1+i2+i3+i4==0) continue;
                if(v[0]+v[2]>0&&v[1]+v[3]>0&&i0+i2+i3+i5==0) continue;
                if(v[0]+v[3]>0&&v[1]+v[2]>0&&i0+i1+i4+i5==0) continue;
                tmp=0;
                for(int i=0;i<4;i++) if(v[i]>0) tmp+=jiko[i];
                if(i0>0) tmp+=e[0][i0-1];
                if(i1>0) tmp+=e[1][i1-1];
                if(i2>0) tmp+=e[2][i2-1];
                if(i3>0) tmp+=e[3][i3-1];
                if(i4>0) tmp+=e[4][i4-1];
                if(i5>0) tmp+=e[5][i5-1];
                ans=max(ans,tmp);
              }
            }
          }
        }
      }
    }
  }
  for(int i=0;i<4;i++) ans=max(ans,jiko[i]);
  cout << ans << endl;
  return 0;
}