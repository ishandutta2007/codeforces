#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

void factor(long long A, vector<long long>& divisors) {
    for (int i=1;(long long) i*i<=A;i++) {
        if (A%i==0) {
            divisors.push_back(i);
            if ((long long) i*i!=A) divisors.push_back(A/i);
        }
    }
}
long long pp(long long x) {
    if (x<=1) return 0;
    for (int i=2;(long long) i*i<=x;i++) {
        if (x%i==0) {
            while (x%i==0) x/=i;
            if (x==1) return i;
            return 0;
        }
    }
    return x;
}

#define MP make_pair
#define A first
#define B second

long long A;
int dp[7000][7000];
vector<long long> divisors;
vector<long long> power;
vector<pair<long long,long long> > primes;
unordered_map<long long,int> loc;

int main() {
    scanf("%I64d",&A);
    if (A==1) return printf("1\n"), 0;
    factor(A,divisors);
    sort(divisors.begin(),divisors.end());
    for (long long& i: divisors) power.push_back(pp(i-1));
    primes.push_back(MP(0,0));
    for (int i=0;i<divisors.size();i++) if (power[i]) {
        primes.push_back(MP(power[i],divisors[i]));
    }
    sort(primes.begin(),primes.end());
    for (int i=0;i<divisors.size();i++) loc[divisors[i]] = i;
    dp[0][0] = 1;
    int where = 0;
    for (int i=1;i<primes.size();i++) {
        if (primes[i].A!=primes[i-1].A) {
            where+=1;
            for (int j=0;j<divisors.size();j++) dp[where][j]+=dp[where-1][j];
        }
        for (int j=0;j<divisors.size();j++) {
            if (1.*divisors[j]*primes[i].B>1e18) continue;
            long long x = divisors[j]*primes[i].B;
            if (A%x==0) dp[where][loc[x]]+=dp[where-1][j];
        }
    }
    printf("%d\n",dp[where][divisors.size()-1]);

    return 0;
}