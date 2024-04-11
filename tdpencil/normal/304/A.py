import math

def ni():
    return int(input())
def vals():
    return list(map(int, input().split()))
def nextLine():
    return input()

n = ni()

ans = 0

for i in range(1, n + 1):
    for j in range(i, n + 1):
        p = i * i + j * j
        p = math.sqrt(p)
        if(int(p) != p or p > n):
            continue

        ans += 1
        # print(i, j, p)

print(ans)