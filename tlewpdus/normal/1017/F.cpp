#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef unsigned int uint;

uint N, a, b, c, d, ans;

uint f(uint x) {
    return d+x*(c+x*(b+x*a));
}

/// @file     segmented_sieve.cpp
/// @author   Kim Walisch, <kim.walisch@gmail.com>
/// @brief    This is a simple implementation of the segmented sieve of
///           Eratosthenes with a few optimizations. It generates the
///           primes below 10^9 in 0.8 seconds (single-threaded) on an
///           Intel Core i7-6700 3.4 GHz CPU.
/// @license  Public domain.

/// Set your CPU's L1 data cache size (in bytes) here
const uint L1D_CACHE_SIZE = 32768;

/// Generate primes using the segmented sieve of Eratosthenes.
/// This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
/// @param limit  Sieve primes <= limit.
///
void segmented_sieve(uint limit)
{
  uint sqt = (uint) sqrt(limit);
  uint segment_size = max(sqt, L1D_CACHE_SIZE);
  uint count = (limit < 2) ? 0 : 1;

  // we sieve primes >= 3
  uint i = 3;
  uint n = 3;
  uint s = 3;

  vector<char> sieve(segment_size);
  vector<char> is_prime(sqt + 1, true);
  vector<uint> primes;
  vector<uint> multiples;

  for (uint low = 0; low <= limit; low += segment_size)
  {
    fill(sieve.begin(), sieve.end(), true);

    // current segment = [low, high]
    uint high = low + segment_size - 1;
    high = min(high, limit);

    // generate sieving primes using simple sieve of Eratosthenes
    for (; i * i <= high; i += 2)
      if (is_prime[i])
        for (uint j = i * i; j <= sqt; j += i)
          is_prime[j] = false;

    // initialize sieving primes for segmented sieve
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
           primes.push_back(s);
        multiples.push_back(s * s - low);
      }
    }

    // sieve the current segment
    for (uint i = 0; i < primes.size(); i++)
    {
      uint j = multiples[i];
      for (uint k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = false;
      multiples[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) {
            uint sum = 0;
            for (int rn = N/n;rn;rn/=n) sum += rn;
            ans += sum*f(n);
      }
  }
    n = 2;
    uint sum = 0;
    for (int rn = N/n;rn;rn/=n) sum += rn;
    ans += sum*f(n);

}

int main() {
    uint i;

    scanf("%u%u%u%u%u",&N,&a,&b,&c,&d);

    segmented_sieve(N);
    printf("%u\n",ans);

    return 0;
}