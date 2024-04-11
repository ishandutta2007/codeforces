#include <bits/stdc++.h>

using namespace std;

long long N, A[100005], par[100005];
vector<vector<long long>> g(100005);
vector<bool> was(100005, false);
long long col[100005]={-1};

void DFS(long long v) {
  was[v]=true;
  for (auto c:g[v]) {
    if (!was[c]){
      DFS(c);
    }
    if(col[c]!=-1 && col[v]==-1) {
      col[v]=1-col[c];
    }
  }
}

int main() {
  scanf("%lld", &N);
  for (long long i=0;i<N;i++) {
    scanf("%i", &A[i]);
    col[i]=-1;
  }
  for (long long i=0;i<N-1;i++) {
    scanf("%lld", &par[i]);
    g[par[i]-1].push_back(i+1);
  }
  vector<long long> leaf;
  for (long long i=0;i<N;i++) {
    if ((long long) g[i].size()==0) {
      col[i]=0;
    }
    leaf.push_back(i);
  }
  DFS(0);
  long long x=-1;
  vector<long long> cc(2,0);
  map<long long,long long> blue;
  map<long long, long long> red;
  for (long long i=0;i<N;i++) {
    //if ((long long) g[i].size()!=0) {
        cc[col[i]]++;
    //}
    if(col[i]==0) {
      blue[A[i]]++;
      if (x==-1) {
        x=A[i];
      } else {
        x^=A[i];
      }
    } else {
      red[A[i]]++;
    }
  }
  map<long long, long long> nw;
  for (long long i=0;i<N;i++) {
    if (col[i]==1) {
      nw[A[i]^x]++;
    }
  }
  if (x==0) {
    long long ans=(long long)(cc[0]*(cc[0]-1)/2)+(long long)(cc[1]*(cc[1]-1)/2);
    for (long long i=0;i<N;i++) {
      if (col[i]==0) {
        ans+=red[A[i]];
      }
    }
    printf("%lld",ans);
  } else {
    long long ans=0;
    for (long long i=0;i<N;i++) {
      if (col[i]==0) {
        ans+=nw[A[i]];
      }
    }
    printf("%lld",ans);
  }
}