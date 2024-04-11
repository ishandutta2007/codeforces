n = int(input())
arr = [0] * 71
a = map(int, input().split())
for i in a:
  arr[i] += 1

dp = [0] * (2**11)
dp[0] = 1
for i in range(71):
  if arr[i] == 0 or i == 37 or i == 41 or i == 43 or i == 47 or i == 53 or i == 59 or i == 61 or i == 67:
    continue
  cur = 0
  primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67]
  for j in range(len(primes)):
    if i > 1 and i % primes[j] == 0:
      x = i
      cnt = 0
      while x % primes[j] == 0:
        x /= primes[j]
        cnt += 1
      if cnt % 2 == 1:
        cur += 2**j
  ndp = [0] * (2**11)
  for x in range(len(dp)):
    ndp[x ^ cur] += dp[x] * pow(2, arr[i] - 1, 10**9 + 7)
    ndp[x ^ cur] %= (10**9 + 7)
    ndp[x] += dp[x] * pow(2, arr[i] - 1, 10**9 + 7)
    ndp[x] %= (10**9 + 7)
  dp = ndp
ans = dp[0]
for i in [37, 41, 43, 47, 53, 59, 61, 67]:
  if arr[i] > 0:
    ans *= pow(2, arr[i] - 1, 10**9 + 7)
    ans %= 10**9 + 7
print((ans + 10**9 + 6) % (10**9 + 7))