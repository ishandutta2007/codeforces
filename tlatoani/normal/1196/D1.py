for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    sums = [0, 0, 0]
    res = 1 << 24
    for i in range(n):
        sums[(333 - ord(s[i]) + i) % 3] -= 1
        if i < k:
            for j in range(3):
                sums[j] += 1
        else:
            sums[(333 - ord(s[i - k]) + i - k) % 3] += 1
        if i >= k - 1:
            res = min(res, min(sums))
    print(res)