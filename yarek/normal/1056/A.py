def read():
    return set(list(map(int, input().split()))[1:])

n = int(input())
t = read()
for _ in range(n - 1):
    t = t & read()

for x in t:
    print(x, end=' ')
print()