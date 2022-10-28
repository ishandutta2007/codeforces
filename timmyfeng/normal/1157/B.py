n = input()
a = map(int, raw_input())
f = [0] + map(int, raw_input().split())

for i in range(0, n):
    if f[a[i]] > a[i]:
        for j in range(i, n):
            if f[a[j]] >= a[j]:
                a[j] = f[a[j]]
            else:
                break
        break

print ''.join([str(i) for i in a])