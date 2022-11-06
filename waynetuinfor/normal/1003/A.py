n = input()
c = [ 0 for i in range(101) ]
a = list(map(int, input().split()))
for i in a: c[i] += 1
ans = 0
for i in range(101):
    if c[i] > ans: ans = c[i]
print(ans)