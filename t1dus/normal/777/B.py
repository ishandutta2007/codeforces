n = int(input())
a = list(input())
b = list(input())
a = [int(i) for i in a]
b = [int(i) for i in b]
a.sort()
b.sort()
c = a[::]
d = b[::]
ans1 = 0
ans2 = 0
for i in a:
    for j in range(len(b)):
        if b[j] > i:
            del b[j]
            ans2 += 1
            break
for i in c:
    for j in range(len(d)):
        if d[j] >= i:
            del d[j]
            break
    else:
        ans1 += 1

print(ans1)
print(ans2)