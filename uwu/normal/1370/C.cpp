#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=31624;

vector<int> primes;
bool sieve[31624];

void generate(){
    ms(sieve,1);
    sieve[1]=sieve[0]=0;
    for (int i=2;i<MAXN;i+=2) sieve[i]=0;
    for (int i=3;i<MAXN;++i){
        if (sieve[i]) primes.push_back(i);
        for (int k=i*i;k<MAXN;k+=i) sieve[k]=0;
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    generate();
    while (t--){
        int n; cin >> n;
        if (n==1){
            cout << "FastestFinger" << '\n';
        }
        else if (n==2){
            cout << "Ashishgup" << '\n';
        }
        else if (n%2==1){
            cout << "Ashishgup" << '\n';
        }
        else if ((n&(n-1))==0){
            cout << "FastestFinger" << '\n';
        }
        else if (n%4==0){
            cout << "Ashishgup" << '\n';
        }
        else{
            n/=2;
            bool flag=true;
            for (int x:primes){
                if (x>=n) break;
                if (n%x==0) flag=false;
            }
            if (flag) cout << "FastestFinger" << '\n';
            else cout << "Ashishgup" << '\n';
        }
    }
}