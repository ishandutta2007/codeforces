A = int(input())
l = 1
r = 10**100
cnt = 10**99*100*45 + 1
cnt = -cnt % A
l += cnt
r += cnt
print(l, r)