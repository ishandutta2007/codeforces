#include <iostream>

using namespace std;

   bool check_prime(int n) {
  bool is_prime = true;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}
int main()
{
   int x,y;
   cin>>x>>y;
   bool resi=true;
   if(!check_prime(y)) resi=false;
    for(int i=x+1;i<y;i++){
        if(check_prime(i)){
            resi=false;
            break;
        }
    }
    if(resi)cout<<"YES\n";
    else cout<<"NO\n";
}