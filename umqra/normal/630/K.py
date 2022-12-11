n = int(input())

ans = n
p = [2, 3, 5, 7]
for i in range(1, 2**4):
    cnt = 0
    value = 1
    for s in range(4):
        if (i & (1 << s)) > 0:
            value *= p[s]
            cnt += 1
    sign = -1 if cnt % 2 == 1 else 1
    ans += sign * (n // value)
print(ans)