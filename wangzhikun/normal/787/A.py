a,b = [int(i) for i in input().split(' ')]
c,d = [int(i) for i in input().split(' ')]
d1 = d%c
ans = -1
b-=a
for i in range(c+120):
    b+=a
    if b%c == d1 and b>=d:
        ans = b
        break
print(ans)