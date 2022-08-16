n = int(input())
home = input()
a = []
for _ in range(n):
    a.append(input().split('->'))
c1 = 0
c2 = 0
for i in a:
    if i[0] == home:
        c1 += 1
    elif i[1] == home:
        c2 += 1
if c1 > c2:
    print("contest")
else:
    print("home")