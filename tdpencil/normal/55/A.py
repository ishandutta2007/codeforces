import math

def ni():
    return int(input())
def vals():
    return list(map(int, input().split()))
def nextLine():
    return input()

n = ni()

works = [0 for i in range(n)]
s = set()
cur = 0
works[cur] = 1
for i in range(1, n + 1):
    cur += i
    works[cur % n] = 1

print("NO" if min(works) < 1 else "YES")