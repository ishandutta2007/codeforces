t = int(input())

amax = 10 ** 4
sq = [False] * (amax + 1)

for x in range(0, amax):
    if x * x > amax:
        break
    sq[x * x] = True

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print('NO' if all([sq[x] for x in a]) else 'YES')