#include<cstdio>
using namespace std;
typedef long long ll;
ll min(ll a, ll b){
  if(a<b)
    return a;
  return b;
}
ll fw[200009];
void add(ll l, ll h){
  while(l<200009){
    fw[l]+=h;
    l|=(l+1);
  }
}
ll res(ll l){
  ll r=0;
  while(l>=0){
    r+=fw[l];
    l=((l+1)&l)-1;
  }
  return r;
}
int main(){
  ll n;
  scanf("%lld",&n);
  for(ll i=0;i<200009;i++){
    fw[i]=0;
  }
  ll com[200009][3];
  ll mad[200009];
  mad[1]=0;
  ll curl;
  ll rel[200009];//after com
  ll lgt[200009];//before com
  curl=1;
  ll sum=0;
  for(ll i=0;i<n;i++){
    if(i!=0)
      printf("%.6f\n",(double)sum/(double)curl);
    scanf("%lld",&(com[i][0]));
    lgt[i]=curl;
    if(com[i][0]==2)
      curl++;
    if(com[i][0]==3)
      curl--;
    if(com[i][0]==3){
      sum-=mad[curl+1]+res(200008-curl-1);
      continue;
    }
    scanf("%lld",&(com[i][1]));
    if(com[i][0]==2){
      sum+=com[i][1];
      com[i][1]-=res(200008-curl);
      mad[curl]=com[i][1];
    }
    if(com[i][0]==2)
      continue;
    scanf("%lld",&(com[i][2]));
    sum+=com[i][2]*com[i][1];
    add(200008-com[i][1],com[i][2]);
  }
  printf("%.6f\n",(double)sum/(double)curl);
  /*
  rel[n-1]=curl;
  for(ll i=n-2;i>=0;i--){
    rel[i]=rel[i+1];
    if(lgt[i+1]<rel[i])
      rel[i]++;
  }
  for(ll i=0;i<n;i++){
    if(com[i][0]==1)
      sum+=min(com[i][1],rel[i])*com[i][2];
    if(com[i][0]==2 && rel[i]==lgt[i+1])
      sum+=com[i][1];
  }
  cout<<(double)sum/(double)curl<<endl;*/
  return 0;
}