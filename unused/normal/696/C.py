MOD = 10**9 + 7
sixinv = pow(6, MOD-2, MOD)
k = int(raw_input())
nums = [int(x) for x in raw_input().split()]
even = False
twok = 2
for n in nums:
    if (n & 1) == 0:
        even = True
    twok = pow(twok, n, MOD)
if even:
    up = twok + 2
else:
    up = twok - 2
down = twok * 3 % MOD
print '%d/%d' % (up * sixinv % MOD, down * sixinv % MOD)