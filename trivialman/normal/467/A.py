n = int(input())
tot = 0
for i in range(n):
    a, b = map(int, input().split())
    tot += (b-a>=2)
print(tot)