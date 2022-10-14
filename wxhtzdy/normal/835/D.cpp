#include <bits/stdc++.h>
using namespace std;
int N;
int dp[5005][5005], cnt[5005];
bool was[5005][5005];
string S;
void cl() {for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j]=0,cnt[i]=0,was[i][j]=false;}
int main() {
  cin>>S;
  int N=(int)S.length(); cl();
  for(int i=1;i<=N;i++){
    for(int j=0;i+j<=N;j++){
      int L=j, R=j+i-1;
      if((i==1 || i==2 || was[L+1][R-1]) && S[L]==S[R]) {
        int mid=(L+R-1)>>1;
        if(mid<0)mid=0;
        dp[L][R]=dp[L][mid]+1;
        cnt[dp[L][R]]++;
        was[L][R]=true;
      }
    }
  }
  for (int i=N-1;i>0;i--) cnt[i]+=cnt[i+1];
  for(int i=1;i<=N;i++) printf("%i ",cnt[i]);
}