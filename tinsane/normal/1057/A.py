n = int(input())
p = list(map(int, input().split()))
l = []
x = n
while x != 1:
    l.append(x)
    x = p[x-2]
l.append(1)
print(' '.join(map(str, l[::-1])))