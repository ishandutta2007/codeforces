l, r = map(int, input().split())
ans = 0
for i in range(31):
    for j in range(31):
        if 2**i * 3 ** j >= l:
            if 2**i * 3**j <=r:
                ans = ans + 1
print(ans)