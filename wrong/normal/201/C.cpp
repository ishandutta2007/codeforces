#include<cstdio>
#include<algorithm>

using namespace std;

#define LL "%I64d"

typedef long long ll;

ll A[100050], L[2][100050], R[2][100050];

int main()
{
  int n;
  scanf("%d", &n);
  
  for(int i=1; i<n; ++i)
    scanf(LL, &A[i]);
  
  L[0][0] = L[1][0] = 0;
  for(int i=1; i<n; ++i) {
    if(A[i] == 1) L[0][i] = 0;
    else L[0][i] = (A[i]&~1) + L[0][i-1];
    L[1][i] = max(L[0][i], (A[i]%2 ? A[i] : A[i]-1)+L[1][i-1]);
  }
  
  R[0][n-1] = R[1][n-1] = 0;
  for(int i=n-2; i>=0; --i) {
    if(A[i+1] == 1) R[0][i] = 0;
    else R[0][i] = (A[i+1]&~1) + R[0][i+1];
    R[1][i] = max(R[0][i], (A[i+1]%2 ? A[i+1] : A[i+1]-1)+R[1][i+1]);
  }
  
  ll sol = 0;
  for(int i=0; i<n; ++i)
    sol = max(sol, max(L[0][i]+R[1][i], L[1][i]+R[0][i]));
  
  printf(LL "\n", sol);
  return 0;
}