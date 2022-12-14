#include<iostream>
#include<vector>
#include<array>
#include<climits>

int main(){
 int ncol;std::cin>>ncol;
 std::vector<std::array<int,3>>data(ncol);
 long long F=LLONG_MIN;
 std::vector<std::array<long long,3>>dp(ncol+1,{F,F,F});
 for(int row=0;row<3;++row)for(int col=0;col<ncol;++col)std::cin>>data[col][row];
 
 //dp[col][row] :: stands at the edge to the left of [row][col], going to move right
 dp[0][0]=0;
 for(int col=0;col<ncol;++col)for(int row=0;row<3;++row){
  if(dp[col][row]==F)break;
  for(int r1=0;r1<3;++r1){
   long long ans=dp[col][row];
   for(int r=0;r<3;++r)
    if(std::min(row,r1)<=r&r<=std::max(row,r1))ans+=data[col][r];
   dp[col+1][r1]=std::max(dp[col+1][r1],ans);
  }
  if(col!=ncol-1&row!=1){
   long long ans=dp[col][row]
    +data[col  ][0]+data[col  ][1]+data[col  ][2]
    +data[col+1][0]+data[col+1][1]+data[col+1][2];
   dp[col+2][2-row]=std::max(dp[col+2][2-row],ans);
  }
 }
 
 std::cout<<dp.back()[2]<<'\n';
}