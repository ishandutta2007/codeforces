a = raw_input()
MOD = 1000000007
ans = 0
na = 0
for i in a:
    if i == 'b':
        ans = (ans + pow(2, na, MOD) - 1) % MOD
    else:
        na += 1
print ans