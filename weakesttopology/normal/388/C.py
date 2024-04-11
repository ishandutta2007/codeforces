n = int(input())

S = [0] * n

ciel, giro = 0, 0
odd = []

for i in range(n):
    L = list(map(int, input().split()))
    k = L[0]
    L = L[1:]

    S[i] = sum(L)

    if k % 2:
        odd.append(L[k // 2])

    ciel += sum(L[:k // 2])
    giro += sum(L[(k + 1) // 2:])

odd.sort(reverse=True)

for i, x in enumerate(odd):
    if i % 2:
        giro += x
    else:
        ciel += x

print(ciel, giro)