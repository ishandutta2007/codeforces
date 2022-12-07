N = int(input())
A = list(map(int, input().split()))

prev_odd = []
ans = 0
for i in range(N):
    if A[i] % 2 == 0:
        ans += A[i] // 2
    else:
        if prev_odd:
            if (i - prev_odd[-1]) % 2 == 1:
                ans += 1
                prev_odd.pop()
            else:
                prev_odd.append(i)
        else:
            prev_odd.append(i)
        ans += A[i] // 2

print(ans)