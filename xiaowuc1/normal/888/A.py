raw_input()
l = [int(x) for x in raw_input().split()]
ret = 0
i = 1
while i+1 < len(l):
    if l[i] > max(l[i-1], l[i+1]):
        ret += 1
    if l[i] < min(l[i-1], l[i+1]):
        ret += 1
    i += 1
print ret