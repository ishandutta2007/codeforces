#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back



int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int n,m,k,t;
 
 cin>>n>>m>>k;
 double lim=1e99;
 std::vector<double> cnk(n+1);
 cnk[0]=1;
 double p=1;
 for(int i=1; i<=n;i++){
	 p*=(double)(n-i+1);
	 p/=(double) i;
	 cnk[i]=p;
 }

 std::vector<double> cmk(m+1);
 cmk[0]=1;
p=1;
 for(int i=1; i<=m;i++){
	 p*=(double)(m-i+1);
	 p/=(double) i;
	 cmk[i]=p;
 }

 std::vector<double> cmxkx(m+1,0);
 cmxkx[0]=1;
 p=1;
 for(int i=1; i<=k;i++){
	 p*=(double)(k-i+1);
	 p/=(double)(m-i+1);
	 cmxkx[i]=p;
 }

 double ans=0;
 for(int a=0;a<=n;a++){
	 for(int b=0;b<=n;b++){
		 int x=(a+b)*n-a*b;
		 /*int al=(k-x+1);
		 int ar=(k);
		 int bl=(m-x+1);
		 int br=m;
		 if(ar>=bl){
			 int sw=ar;
			 ar=bl-1;
			 bl=sw+1;			 

		 }
		 if(al<=0) p=0;
		 else{
			 p=1;
			 for(int i=0;i<=(ar-al);i++){
				 p*=(double)(al+i)/(double)(bl+i);
			 }

		 }*/
		 double q=cmxkx[x];
		 ans+=cnk[a]*cnk[b]*q;
		 if(ans>lim){
			 printf("1e99");
			 return 0;
		 }
	 }
 }
 printf("%.10f", ans);

}