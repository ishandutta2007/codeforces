n = int(input())
a = list(map(int, input().split()))
c = [ 0 for i in range(1000001) ]
s = sum(a)
ans = []
for i in a: c[i] += 1
for i in range(n):
    s -= a[i]
    c[a[i]] -= 1
    if s % 2 == 0 and s // 2 <= 1000000 and c[s // 2] > 0:
        ans.append(i)
    s += a[i]
    c[a[i]] += 1
print(len(ans))
for i in ans:
    print(i + 1, end=' ')