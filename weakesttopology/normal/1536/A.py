t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if min(a) < 0 and max(a) != min(a):
        print('NO')
        continue
    elif min(a) >= 0:
        d = max(a)
        for x in range(d + 1):
            a.append(x)
        a = list(set(a))
    print('YES')
    print(len(a))
    print(*a)