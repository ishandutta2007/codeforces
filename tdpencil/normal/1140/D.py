import math

def ni():
    return int(input())
def vals():
    return list(map(int, input().split()))
def nextLine():
    return input()

n = ni()

ans = 0
for i in range(2, n):
    ans += i * (i + 1)

print(ans)