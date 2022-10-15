#include <bits/stdc++.h>
 
using namespace std; 
 
int n;
char A[200000];
char B[200000];
int C[200000];
int D[200000];
 
void solve(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", C + i, D + i);
 
    A[n] = 0;
    B[n] = 0;
 
    for (int i = 0; i < n/2; ++i){
        A[i]='1'; B[i]='1';
    }
    for (int i = n/2; i < n; ++i){
        A[i]='0'; B[i]='0';
    }
 
    int a = 0, b = 0;
    for(int i=0; i<n; i++){
        if(C[a] < D[b]){
            A[a] = '1'; ++a;
        }
        else{
            B[b] = '1'; ++b;
        }
  }
 
 
    // cout << A << " " << B << "\n";
    printf("%s\n%s\n", A, B);
}
 
int main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0);
 
    // freopen("file.in","r",stdin); 
	// freopen("file.out","w",stdout); 
 
    int t=1;
 
    while(t--){
        solve();
    }
}