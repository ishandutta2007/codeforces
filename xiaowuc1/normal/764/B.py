n = int(raw_input())
l = raw_input().split()
a = 0
b = n-1
while a < b:
    t = l[a]
    l[a] = l[b]
    l[b] = t
    a += 2
    b -= 2
print " ".join(l)