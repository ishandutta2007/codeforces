n = int(input())
a = []
b = []
for _ in range(n):
    x = input().split()
    a.append(x[0])
    b.append(x[1])
coun = 0
for i in a:
    for j in b:
        if i == j:
            coun += 1
print(coun)