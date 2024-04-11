#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const ll inf=1e18+99;
#define fi first
#define se second
#define pb push_back

const int N=2048;
int n,m;
bitset<N+N> A[N];
short a[1<<19],b[1<<19];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d%d",a+i,b+i);
	for(int i=0;i<m;i++) --a[i], --b[i];
	for(int i=0;i<m;i++) A[a[i]][b[i]]=1;
	// for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i].flip(j);

   for(int i=0;i<n;i++)
      for(int j=n;j<n+n;j++)
      	A[i][j]=(i==j-n);

   for(int i=0;i<n;i++)
   {
      int ii=i;
      for(;ii<=n;ii++) {
      	assert(ii!=n);
      	if(A[ii][i]) break;
      }
      if(ii!=i) swap(A[i],A[ii]);
      assert(A[i][i]);

      for(int j=0;j<n;j++) {
         if(i!=j && A[j][i])
         	A[j]^=A[i];
      }
   }
   for(int i=0;i<m;i++) {
   	if(!A[b[i]][a[i]+n]) printf("YES\n");
   	else printf("NO\n");
   }
}