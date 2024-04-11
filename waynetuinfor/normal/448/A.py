a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
N = int(input())
medal = sum(b)
cups = sum(a)
for i in range(N):
    if medal:
        if medal > 10:
            medal -= 10
        else:
            medal = 0
    elif cups:
        if cups > 5:
            cups -= 5
        else: cups = 0

if medal > 0 or cups > 0:
    print("NO")
else:
    print("YES")